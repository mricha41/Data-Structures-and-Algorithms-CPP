#include <iostream>
#include <cassert>

template <std::size_t queueSize, class C1>
CircularQueue<queueSize, C1>::CircularQueue()
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
CircularQueue<queueSize, C1>::CircularQueue(T... elements)
    :
    m_data{ elements... },
    m_maxSize(queueSize),
    m_front(0)
{
    assert((sizeof...(elements) > 0) && "Instantiate the array with more than zero elements.");
    m_size = sizeof...(elements);
    m_back = m_size;
}

template <std::size_t queueSize, class C1>
CircularQueue<queueSize, C1>::~CircularQueue()
{

}

template <std::size_t queueSize, class C1>
C1& CircularQueue<queueSize, C1>::front() 
{
    assert((m_size > 0) && "CircularQueue is empty!");
    assert((m_front >= 0 && m_front <= m_maxSize) && "CircularQueue overflow or underflow occurred!\n");

    return m_data[m_front];
}

template <std::size_t queueSize, class C1>
C1& CircularQueue<queueSize, C1>::back()
{
    assert((m_size > 0) && "CircularQueue is empty!");
    assert((m_back >= 0 && m_back <= m_maxSize) && "CircularQueue overflow or underflow occurred!\n");

    if (m_back == m_size)
        return m_data[m_size - 1];
    return m_data[m_back];
}

template <std::size_t queueSize, class C1>
C1& CircularQueue<queueSize, C1>::operator [] (std::size_t index)
{
    //if user passes negative value (an int), it will be cast to std::size_t.
    //std::size_t wraps to the largest available value on negatives...
    //so cast it back to int for this first check
    assert(((int)index >= 0) && "Subscript is beyond the lower bound of the CircularQueue!");
    //assert((index <= m_back) && "Subscript is beyond the upper bound of the CircularQueue!");

    return m_data[index];
}

//read-only version
template <std::size_t queueSize, class C1>
const C1& CircularQueue<queueSize, C1>::operator [] (std::size_t index) const
{
    assert(((int)index >= 0) && "Subscript is beyond the lower bound of the CircularQueue!");
    assert((index <= m_back) && "Subscript is beyond the upper bound of the CircularQueue!");

    return m_data[index];
}

template <std::size_t queueSize, class C1>
void CircularQueue<queueSize, C1>::push(C1 value)
{
    //assert((m_back + 1 % m_maxSize != m_front) && "CircularQueue overflow!\n");
    assert((m_size < m_maxSize) && "CircularQueue overflow!\n");

    m_data[m_back] = value;
    m_back = m_back + 1 % m_maxSize;
    m_size++;
}

template <std::size_t queueSize, class C1>
C1 CircularQueue<queueSize, C1>::pop()
{
    assert((m_size > 0) && "CircularQueue is empty!");
    C1 temp = C1();

    temp = m_data[m_front];
    m_front = m_front + 1 % m_maxSize;
    m_size--;

    return temp;
}