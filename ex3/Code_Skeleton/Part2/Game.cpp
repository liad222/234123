#include "Game.hpp"

/*--------------------------------------------------------------------------------
								
--------------------------------------------------------------------------------*/
void string2bool(game_params g, bool_mat *x) {
    vector<string> temp = utils::read_lines(g.filename);
    uint col = (temp.front()).length();
    uint row = temp.size();
        for (uint i = 0; i < row; ++i) {
        vector<bool> line;
        for (uint j = 0; j < col; ++j) {
            if (((temp[i])[j] == ' '))
                continue;
            bool val = ((temp[i])[j] == '1');
            line.push_back(val);
        }
        x->push_back(line);
    }
}

Game::Game(game_params g) {
    gparams = g;
    m_gen_num = g.n_gen;
    interactive_on = g.interactive_on;
    print_on = g.print_on;
    boards[0] = vector<vector<bool>>();
    boards[1] = vector<vector<bool>>();
    string2bool(g, &(boards[0]));
    string2bool(g, &(boards[1]));
    curr = &boards[0];
    next = &boards[1];
    row = (*curr).size();
    col = ((*curr)[0]).size();
    m_thread_num = thread_num();
    pthread_mutexattr_t attr;            //lock init
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_t error_check_mutex;
    pthread_mutex_init(&error_check_mutex, &attr);
    lock = error_check_mutex;
    pthread_mutexattr_t attr2;            //lock init
    pthread_mutexattr_init(&attr2);
    pthread_mutexattr_settype(&attr2, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_t error_check_mutex2;
    pthread_mutex_init(&error_check_mutex2, &attr2);
    Tlock = error_check_mutex;
    tasks = PCQueue<int *>();
    m_threadpool = vector<Thread*>();
    m_tile_hist = vector<float>();
    m_gen_hist = vector<float>();
}


uint Game::thread_num() const {
    if (row > gparams.n_thread)
        return gparams.n_thread;
    else
        return row;
}

void Game::run() {
    _init_game(); // Starts the threads and all other variables you need
    print_board("Initial Board");
    for (uint i = 0; i < m_gen_num; ++i) {
        auto gen_start = std::chrono::system_clock::now();
        _step(i); // Iterates a single generation
        auto gen_end = std::chrono::system_clock::now();
        m_gen_hist.push_back(
                (float) std::chrono::duration_cast<std::chrono::microseconds>(
                        gen_end - gen_start).count());
        print_board(NULL);
    } // generation loop
    print_board("Final Board");
    _destroy_game();
}

void Game::_init_game() {
    // Create threads
    // Create game fields
    // Start the threads
    // Testing of your implementation will presume all threads are started here
    for (int i = 0; i < m_thread_num; ++i) {
        m_threadpool.push_back(new game_Thread(i, &curr, &next, row, col, &tasks,
                                               &lock,&Tlock, &m_tile_hist));

    }
    for (int i = 0; i < m_thread_num; ++i) {
        (m_threadpool[i])->start();
    }
}

void Game::_step(uint curr_gen) {
    // Push jobs to queue
    // Wait for the workers to finish calculating
    // Swap pointers between current and next field

    int diff = row / m_thread_num;
    int **arr = new int* [m_thread_num];
    for (int i = 0; i < m_thread_num - 1; ++i) {
         int *x = new int[2];
         arr[i] = x;
        (arr[i])[0] = diff * i;
        (arr[i])[1] = diff * (i + 1) - 1;
        tasks.push(arr[i]);
    }
    int *last = new int[2];
    arr[m_thread_num - 1] = last;
    (arr[m_thread_num - 1])[0] = diff * (m_thread_num - 1);
    (arr[m_thread_num - 1])[1] = row - 1;
    //arr[m_thread_num] = nullptr;
    tasks.push(arr[m_thread_num - 1]);
    ///waiting for the threads to finish
    while (m_tile_hist.size() != m_thread_num*(curr_gen+1));///thread_num is also the number of tasks

    delete[](arr);
    ///swap
    bool_mat *temp = curr;
    curr = next;
    next = temp;
}

void Game::_destroy_game() {
    // Destroys board and frees all threads and resources
    // Not implemented in the Game's destructor for testing purposes.
    // Testing of your implementation will presume all threads are joined here
    int **arr = new int* [m_thread_num];
    for (int i = 0; i < m_thread_num; ++i) {
        int *x = new int[2];
        arr[i] = x;
        (arr[i])[0] = -1;
        (arr[i])[1] = -1;
        tasks.push(arr[i]);
    }
    //arr[m_thread_num] = nullptr;
    //tasks.pushmany(arr);
    for (int i = m_thread_num-1; i >= 0; --i) {
        m_threadpool[i]->join();
    }
    delete[](arr);
   /* while (tasks_completed.getQueueSize() != 0) {
        int *temp =  tasks_completed.pop();
        delete[](temp);
    }*/
   while (!m_threadpool.empty()){
        Thread* temp = m_threadpool.back();       ///not sure if correct,from what i understand we alocated the
        /// "game_Threads" so we need to delete them, the waiting only works the the thread itself not for the class
        m_threadpool.pop_back();
        delete temp;
    }

}

/*--------------------------------------------------------------------------------
								
--------------------------------------------------------------------------------*/
inline void Game::print_board(const char *header) {
    if (print_on) {

        // Clear the screen, to create a running animation
        if (interactive_on)
            system("clear");

        // Print small header if needed
        if (header != NULL)
            cout << "<------------" << header << "------------>" << endl;

        // TODO: Print the board
        bool_mat *field = curr;
        int field_width = col;
        int field_height = row;

        cout << u8"╔" << string(u8"═") * field_width << u8"╗" << endl;
        for (uint i = 0; i < field_height; ++i) {
            cout << u8"║";
            for (uint j = 0; j < field_width; ++j) {
                cout << ((*field)[i][j] ? u8"█" : u8"░");
            }
            cout << u8"║" << endl;
        }
        cout << u8"╚" << string(u8"═") * field_width << u8"╝" << endl;

        // Display for GEN_SLEEP_USEC micro-seconds on screen
        if (interactive_on)
            usleep(GEN_SLEEP_USEC);
    }

}

const vector<float> Game::gen_hist() const{
    return m_gen_hist;
}
const vector<float> Game::tile_hist() const{
    return m_tile_hist;
}

/* Function sketch to use for printing the board. You will need to decide its placement and how exactly 
	to bring in the field's parameters. 

		cout << u8"╔" << string(u8"═") * field_width << u8"╗" << endl;
		for (uint i = 0; i < field_height ++i) {
			cout << u8"║";
			for (uint j = 0; j < field_width; ++j) {
				cout << (field[i][j] ? u8"█" : u8"░");
			}
			cout << u8"║" << endl;
		}
		cout << u8"╚" << string(u8"═") * field_width << u8"╝" << endl;
*/ 



