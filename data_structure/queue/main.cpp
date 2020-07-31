#include "queue.h"
#include <iostream>

int main(void)
{
    Queue que;

    std::cout << que.max_size() << std::endl;
    std::cout << "que.size : " << que.size() << std::endl;

    que.push(100);
    que.push(200);

    std::cout << "que.size : " << que.size() << std::endl;

    std::cout << "que.front : " << que.front() << std::endl;
    que.pop();
    std::cout << "que.front : " << que.front() << std::endl;

    if(que.empty()) std::cout << "que is empty." << std::endl;
    else            std::cout << "que is not empty." << std::endl;

    que.pop();

    if(que.empty()) std::cout << "que is empty." << std::endl;
    else            std::cout << "que is not empty." << std::endl;

    return 0;
}