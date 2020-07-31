#include "queue.h"

Queue::Queue()
{
    this->head = 0;
    this->idx = -1;
}

Queue::~Queue()
{
}

int Queue::push(int value)
{
    v[++(this->idx)] = value;

    if(this->idx == 0)
    {
        this->head = value;
    }

    return value;
}

int Queue::front()
{
    return this->head;
}

void Queue::pop()
{
    for (int i = 1; i <= this->idx; i++)
    {
        this->v[i - 1] = this->v[i];
    }

    this->head = this->v[0];

    this->idx --;
}

int Queue::size()
{
    return this->idx + 1;
}

int Queue::max_size()
{
    return (sizeof(this->v) / sizeof(int));
}

bool Queue::empty()
{
    if(this->idx == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}