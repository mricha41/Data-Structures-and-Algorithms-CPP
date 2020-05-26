#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <tuple>
#include <initializer_list>

template <std::size_t arraySize, class C1>
class Array
{
private:
    

public:
   
    Array();
    
    template <typename... T>
    Array(T... elements);

    ~Array();

    C1 &operator [] (std::size_t index);

    const C1 &operator [] (std::size_t index) const;

    C1 *data(){ return m_data; };

    void clear();

    std::size_t MaxSize(){ return m_maxSize; };
    std::size_t Size(){ return m_size; };

    C1 Front(){ return m_data[0]; };
    C1 Back(){ return m_data[m_size - 1]; };

    void Append(C1 value);

    void Insert(std::size_t index, C1 value);

    void Remove(std::size_t index);

    //these have little meaning
    //outside numeric types...
    C1 Min();
    C1 Max();
    std::tuple<C1, C1> MinMax();

    bool IsSorted();

    void InsertionSort(C1 x);

private:
    std::size_t m_maxSize;
    std::size_t m_size;
    C1 m_data [arraySize];
};

//weird template way of doing things...
//since all generated code needs to be
//in one translation unit
#include "Array.inl"

#endif // ARRAY_HPP
