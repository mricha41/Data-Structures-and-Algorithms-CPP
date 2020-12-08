#include <iostream>
#include <cassert>

template <std::size_t stackSize, class C1>
Stack<stackSize, C1>::Stack()
    :
    m_maxSize(stackSize),
    m_size(0),
    m_top(0)
{
    
}

template <std::size_t stackSize, class C1>
template <typename... T>
Stack<stackSize, C1>::Stack(T... elements)
    :
    m_maxSize(stackSize),
    m_data{ elements... }
{
    assert((sizeof...(elements) > 0) && "Instantiate the array with more than zero elements.");
    m_size = sizeof...(elements);
    m_top = m_size - 1;
}

template <std::size_t stackSize, class C1>
Stack<stackSize, C1>::~Stack()
{

}

template <std::size_t stackSize, class C1>
C1& Stack<stackSize, C1>::operator [] (std::size_t index)
{
    //if user passes negative value (an int), it will be cast to std::size_t.
    //std::size_t wraps to the largest available value on negatives...
    //so cast it back to int for this first check
    assert(((int)index >= 0) && "Subscript is beyond the lower bound of the stack!");
    assert((index < m_size) && "Subscript is beyond the upper bound of the stack!");

    return m_data[index];
}

//read-only version
template <std::size_t stackSize, class C1>
const C1& Stack<stackSize, C1>::operator [] (std::size_t index) const
{
    assert(((int)index >= 0) && "Subscript is beyond the lower bound of the stack!");
    assert((index < m_size) && "Subscript is beyond the upper bound of the stack!");

    return m_data[index];
}

template <std::size_t stackSize, class C1>
void Stack<stackSize, C1>::push(C1 value)
{
    assert((m_top < m_maxSize - 1) && "Stack overflow!\n");

    if (m_size == 0)
    {
        m_data[m_top] = value;
    }
    else
    {
        m_top++;
        m_data[m_top] = value;
    }

    m_size++;
}

template <std::size_t stackSize, class C1>
C1& Stack<stackSize, C1>::pop()
{
    assert((m_top >= 0) && "Stack underflow!\n");
    
    m_size--;
    return m_data[m_top--];
}