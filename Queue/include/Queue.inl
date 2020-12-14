#include <iostream>
#include <cassert>

template <std::size_t queueSize, class C1>
Queue<queueSize, C1>::Queue()
    :
    m_maxSize(queueSize),
    m_size(0),
    m_front(0),
    m_back(0),
    m_data{}
{
    
}

template <std::size_t queueSize, class C1>
template <typename... T>
Queue<queueSize, C1>::Queue(T... elements)
    :
    m_maxSize(queueSize),
    m_data{ elements... }
{
    assert((sizeof...(elements) > 0) && "Instantiate the array with more than zero elements.");
    m_size = sizeof...(elements);
    m_front = 0;
    m_back = m_size - 1;
}

template <std::size_t queueSize, class C1>
Queue<queueSize, C1>::~Queue()
{

}
template <std::size_t queueSize, class C1>
C1& Queue<queueSize, C1>::front() 
{ 
    assert((m_front >= 0 && m_front <= m_maxSize) && "Queue overflow or underflow occurred!\n");

    return m_data[m_front];
}

template <std::size_t queueSize, class C1>
C1& Queue<queueSize, C1>::back()
{
    assert((m_back >= 0 && m_back < m_maxSize) && "Queue overflow or underflow occurred!\n");

    return m_data[m_back];
}

template <std::size_t queueSize, class C1>
C1& Queue<queueSize, C1>::operator [] (std::size_t index)
{
    //if user passes negative value (an int), it will be cast to std::size_t.
    //std::size_t wraps to the largest available value on negatives...
    //so cast it back to int for this first check
    assert(((int)index >= 0) && "Subscript is beyond the lower bound of the Queue!");
    assert((index <= m_back) && "Subscript is beyond the upper bound of the Queue!");

    return m_data[index];
}

//read-only version
template <std::size_t queueSize, class C1>
const C1& Queue<queueSize, C1>::operator [] (std::size_t index) const
{
    assert(((int)index >= 0) && "Subscript is beyond the lower bound of the Queue!");
    assert((index <= m_back) && "Subscript is beyond the upper bound of the Queue!");

    return m_data[index];
}

template <std::size_t queueSize, class C1>
void Queue<queueSize, C1>::push(C1 value)
{
    assert((m_back < m_maxSize - 1) && "Queue overflow!\n");

    //std::cout << "front index: " << m_front << "\n";
    //std::cout << "back index: " << m_back << "\n";

    if(m_size > 0)
        m_back++;

    m_data[m_back] = value;
    m_size++;
}

template <std::size_t queueSize, class C1>
C1 Queue<queueSize, C1>::pop()
{
    assert((m_front >= 0) && "Queue underflow!\n");

    C1 temp = C1();
    if (m_front != m_back)
    {
        temp = m_data[m_front];
        m_front++;
        m_size--;
        return temp;
    }
    else
    {
        temp = m_data[m_back];
        m_size = 0;
        m_front = 0;
        m_back = 0;
        return temp;
    }

    std::cout << "Queue is empty, empty value returned." << "\n";
    return C1();
}