#pragma once

#include <vector>

class Queue
{
    private:
        int v[10000];
        int head;
        int idx;
    public:
        Queue();
        ~Queue();

        int push(int value);
        int front();
        void pop();
        int size();
        int max_size();
        bool empty();
};