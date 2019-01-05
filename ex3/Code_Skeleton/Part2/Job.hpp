//
// Created by Liad on 05/01/2019.
//

#ifndef EX3_JOB_HPP
#define EX3_JOB_HPP


class Job{
public:
    int first;
    int last;
    Job(int first=0, int last=0):first(first),last(last){}
    Job& operator= (const Job& x){
        this->first = x.first;
        this->last = x.last;
        return *this;
    }
};


#endif //EX3_JOB_HPP
