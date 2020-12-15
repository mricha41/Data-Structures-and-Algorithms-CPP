#include "CircularQueue.hpp"

template <std::size_t queueSize, class T1>
void Display(CircularQueue<queueSize, T1> queue)
{
    assert(queue.m_maxSize > 0 &&
        "Your queue is empty. This function requires a non-empty stack.");
    
    std::cout << "CircularQueue max size: " << queue.m_maxSize << std::endl;
    std::cout << queue.m_size << " Elements in CircularQueue: " << std::endl;
    //std::cout << "init: " << queue.m_front << "\n";
    //std::cout << "base case: " << (queue.m_back + 1 % queue.m_size) - 1 << "\n";
    for (std::size_t i = queue.m_front; i < (queue.m_back + 1 % queue.m_maxSize) - 1; i = i + 1 % queue.m_maxSize)
    {
        std::cout << queue[i] << "\n";
    }

    std::cout << "\n\n";
}