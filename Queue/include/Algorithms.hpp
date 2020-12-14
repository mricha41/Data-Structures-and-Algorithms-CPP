#include "Queue.hpp"

template <std::size_t queueSize, class T1>
void Display(Queue<queueSize, T1> queue)
{
    assert(queue.size() > 0 &&
        "Your queue is empty. This function requires a non-empty stack.");
    
    std::cout << "Queue size: " << queue.size() << std::endl;
    std::cout << "Elements in Queue: " << std::endl;
    for (std::size_t i = queue.m_front; i <= queue.m_back; ++i)
    {
        std::cout << queue[i] << "\n";
    }
    std::cout << "\n\n";
}