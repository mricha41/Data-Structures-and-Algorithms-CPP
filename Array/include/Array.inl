#include <cassert>

template <std::size_t arraySize, class C1>
Array<arraySize, C1>::Array()
:
    m_maxSize(arraySize)
{
    m_size = 0;
}

template <std::size_t arraySize, class C1>
template <typename... T>
Array<arraySize, C1>::Array(T... elements)
:
    m_maxSize(arraySize),
    m_data{elements...}
{
    assert((sizeof...(elements) > 0) && "Instantiate the array with more than zero elements.");
    m_size = sizeof...(elements);
}

template <std::size_t arraySize, class C1>
Array<arraySize, C1>::~Array()
{

}

template <std::size_t arraySize, class C1>
C1 &Array<arraySize, C1>::operator [] (std::size_t index)
{
    //if user passes negative value (an int), it will be cast to std::size_t.
    //std::size_t wraps to the largest available value on negatives...
    //so cast it back to int for this first check
    assert(((int)index >= 0) && "Array subscript is beyond the lower bound of the array!");
    assert((index < m_size) && "Array subscript is beyond the upper bound of the array!");

    return m_data[index];
}

//read-only version
template <std::size_t arraySize, class C1>
const C1 &Array<arraySize, C1>::operator [] (std::size_t index) const
{
    assert(((int)index >= 0) && "Array subscript is beyond the lower bound of the array!");
    assert((index < m_size) && "Array subscript is beyond the upper bound of the array!");

    return m_data[index];
}

template <std::size_t arraySize, class C1>
void Array<arraySize, C1>::clear()
{
    assert((m_size > 0) && "There are no elements in the array to clear.");

    //requires cast to fill with default value of deduced type
    //applies only to elements with values (size), not entire array (max size)
    for(std::size_t i = 0; i<m_size; ++i)
        m_data[i] = static_cast<C1>(0);

    m_size = 0;
}

template <std::size_t arraySize, class C1>
void Array<arraySize, C1>::Append(C1 value)
{
    assert((m_size < m_maxSize) && "You've tried to append an element to an array that is already at max capacity. Declare an array with a larger size and try again.");

    m_data[m_size] = value;
    m_size++;
}

template <std::size_t arraySize, class C1>
void Array<arraySize, C1>::Insert(std::size_t index, C1 value)
{
    //cast passed value to int, see explanation in operator [] overload above
    //regarding st::size_t wrapping on negatives...
    assert(((int)index >= 0) && "You've tried to insert an element outside the lower bound of the array. Pick another index and try again.");
    assert((index < m_size) && "You've tried to insert an element outside the upper bound of the array. Pick another index and try again.");
    assert((m_size + 1 <= m_maxSize) && "You've tried to insert an element into an array that is already at max capacity. Declare an array with a larger size and try again.");

    //shift all remaining elements to the right after index...
    for(std::size_t i = m_size; i > index; --i)
    {
        m_data[i] = m_data[i - 1];
    }
    //...then assign the value at the index specified
    m_data[index] = value;
    m_size++;
}

template <std::size_t arraySize, class C1>
void Array<arraySize, C1>::Remove(std::size_t index)
{
    //cast passed value to int, see explanation in operator [] overload above
    //regarding st::size_t wrapping on negatives...
    assert(((int)index >= 0) && "You've tried to delete an element outside the lower bound of the array. Pick another index and try again.");
    assert((index <= m_size) && "You've tried to delete an element outside the upper bound of the array. Pick another index and try again.");

    //shift all values one position to the left
    //after the index specified which overwrites at the index
    for(std::size_t i=index; i < m_maxSize-1; ++i)
    {
        m_data[i] = m_data[i + 1];
    }
    m_size--;
}

template <std::size_t arraySize, class C1>
C1 Array<arraySize, C1>::Min()
{
    assert(m_size > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    C1 min = m_data[0];

    for(std::size_t i = 0; i < m_size; ++i)
    {
        if(m_data[i] < min)
            min = m_data[i];
    }

    return min;
}

template <std::size_t arraySize, class C1>
C1 Array<arraySize, C1>::Max()
{
    assert(m_size > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    C1 max = m_data[0];

    for(std::size_t i = 0; i < m_size; ++i)
    {
        if(m_data[i] > max)
            max= m_data[i];
    }

    return max;
}

template <std::size_t arraySize, class C1>
std::tuple<C1, C1> Array<arraySize, C1>::MinMax()
{
    assert(m_size > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    return {Min(), Max()};
}

template <std::size_t arraySize, class C1>
void Array<arraySize, C1>::InsertionSort(C1 x)
{
    assert(m_size > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    if(m_size == m_maxSize)
        return;

    std::size_t i = m_size - 1;
    for(; i>=0 && m_data[i] > x; --i)
    {
        m_data[i + 1] = m_data[i];
    }

    m_data[i + 1] = x;
    m_size++;
}

template <std::size_t arraySize, class C1>
bool Array<arraySize, C1>::IsSorted()
{
    assert(m_size > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    for(std::size_t i = 0; i < m_size - 1; ++i)
    {
        if(m_data[i] > m_data[i + 1])
            return false;
    }
    return true;
}
