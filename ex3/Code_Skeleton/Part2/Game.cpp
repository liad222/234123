#include "Game.hpp"

/*--------------------------------------------------------------------------------
								
--------------------------------------------------------------------------------*/
void string2bool(game_params g, bool_mat x) {
    vector<string> temp = utils::read_lines(g.filename);
    uint col = (temp.front()).length();
    uint row = temp.size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            x[row][col] = ((temp[i])[j] == '1');
        }
    }
}

Game::Game(game_params g) {
    cout << "<------------" << "HERE1" << "------------>" << endl;
    gparams = g;
    interactive_on = g.interactive_on;
    print_on = g.print_on;
    string2bool(g, boards[0]);
    string2bool(g, boards[1]);
    curr = &boards[0];
    next = &boards[1];
    row = boards[0].size();
    col = (boards[0].front()).size();
    m_thread_num = thread_num();
    lock = Semaphore(1);
    tasks = PCQueue<int *>();
    tasks_completed = PCQueue<int *>();
    cout << "<------------" << "HERE2" << "------------>" << endl;
}


uint Game::thread_num() const {
    if (row > gparams.n_thread)
        return gparams.n_thread;
    else
        return row;
}

void Game::run() {
    cout << "<------------" << "HERE3" << "------------>" << endl;
    _init_game(); // Starts the threads and all other variables you need
    print_board("Initial Board");
    for (uint i = 0; i < m_gen_num; ++i) {
        auto gen_start = std::chrono::system_clock::now();
        cout << "<------------" << "HERE4" << "------------>" << endl;
        _step(i); // Iterates a single generation
        auto gen_end = std::chrono::system_clock::now();
        m_gen_hist.push_back(
                (float) std::chrono::duration_cast<std::chrono::microseconds>(
                        gen_end - gen_start).count());
        cout << "<------------" << "HERE5" << "------------>" << endl;
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
        m_threadpool[i] = new game_Thread(i, curr, next, row, col, &tasks,&tasks_completed,
                                          &lock);
    }
    for (int i = 0; i < m_thread_num; ++i) {
        m_threadpool[i]->start();
    }
}

void Game::_step(uint curr_gen) {
    // Push jobs to queue
    // Wait for the workers to finish calculating
    // Swap pointers between current and next field
    int arr[2];
    int diff = row / m_thread_num;
    for (int i = 0; i < m_thread_num - 1; ++i) {
        arr[0] = diff * i;
        arr[1] = diff * (i + 1) - 1;
        tasks.push(arr);
    }
    arr[0] = diff * (m_thread_num - 1);
    arr[1] = row - 1;
    tasks.push(arr);
    ///waiting for the threads to finish
    while(tasks_completed.getQueueSize()!=m_thread_num) ;///thread_num is also the number of tasks
    /*
    int allDone = 0;
    while(allDone != m_thread_num) {
        allDone = 0;
        for (int j = 0; j < m_thread_num; ++j) {
            if(m_threadpool[j]->getDone() == 1){
                allDone++;
            }
        }
    }
    */
    ///emptying the task _completed q for the next run
    while(tasks_completed.getQueueSize()!=0) {
        tasks_completed.pop();
    }


    /* restarting the done flag
    for (int j = 0; j < m_thread_num; ++j) {
        m_threadpool[j]->setDone(0);
    }*/
    ///swap
    bool_mat *temp = curr;
    curr = next;
    next = temp;
}

void Game::_destroy_game() {
    // Destroys board and frees all threads and resources
    // Not implemented in the Game's destructor for testing purposes.
    // Testing of your implementation will presume all threads are joined here
    int arr[2];
    arr[0] = -1;
    arr[1] = -1;
    for (int i = 0; i < m_thread_num - 1; ++i) {
        tasks.push(arr);
    }
    for (int i = 0; i < m_thread_num; ++i) {
        m_threadpool[i]->join();
    }
    for (int i = 0; i < m_thread_num; ++i) {
        delete m_threadpool[i];
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



