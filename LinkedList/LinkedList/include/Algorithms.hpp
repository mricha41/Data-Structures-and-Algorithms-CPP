#include "List.hpp"

#include <utility>

template<typename T>
void DisplayList(List<T>& list)
{
	Node<T>* temp = list.begin();
	while (temp != nullptr)
	{
		std::cout << temp->m_data << std::endl;
		temp = temp->m_next;
	}
}

template<typename T>
void DisplayListRecursive(Node<T>* first)
{
	Node<T>* temp = first;
	if (temp != nullptr)
	{
		std::cout << temp->m_data << std::endl;
		DisplayListRecursive(temp->m_next);
	}
}

//Numeric Operations
//only make sense for numeric values
//works for any type where the + operator is overloaded
template<typename T>
T Sum(List<T>& list)
{
	Node<T>* temp = list.begin();
	T sum = T();
	while (temp != nullptr)
	{
		sum = sum + temp->m_data;
		temp = temp->m_next;
	}
	return sum;
}

template<typename T>
T SumRecursive(Node<T>* first)
{
	Node<T>* temp = first;
	if (temp == nullptr)
		return T();
	else
		return SumRecursive(temp->m_next) + temp->m_data;
}

template<typename T>
T Max(List<T>& list)
{
	Node<T>* temp = list.begin();
	T max = std::numeric_limits<T>::min();
	while (temp != nullptr)
	{
		if (temp->m_data > max)
			max = temp->m_data;

		temp = temp->m_next;
	}
	
	return max;
}

template<typename T>
T MaxRecursive(Node<T>* first)
{
	Node<T>* temp = first;
	T max = T();
	if (temp == nullptr)
		return std::numeric_limits<T>::min();

	max = MaxRecursive(temp->m_next);
	return max > temp->m_data ? max : temp->m_data;
}


template<typename T>
T Min(List<T>& list)
{
	Node<T>* temp = list.begin();
	T min = std::numeric_limits<T>::max();
	while (temp != nullptr)
	{
		if (temp->m_data < min)
			min = temp->m_data;

		temp = temp->m_next;
	}

	return min;
}

template<typename T>
T MinRecursive(Node<T>* first)
{
	Node<T>* temp = first;
	T min = T();
	if (temp == nullptr)
		return std::numeric_limits<T>::max();

	min = MinRecursive(temp->m_next);
	return min < temp->m_data ? min : temp->m_data;
}

template<typename T>
std::pair<T, T> MinMax(List<T>& list)
{
	return std::pair<T, T>(Min(list), Max(list));
}

template<typename T>
std::pair<T, T> MinMaxRecursive(List<T>& list)
{
	return std::pair<T, T>(MinRecursive(list.begin()), MaxRecursive(list.begin()));
}

template<typename T>
Node<T>* LinearSearch(Node<T>* first, T key)
{
	while (first != nullptr)
	{
		if (key == first->m_data)
			return first;

		first = first->m_next;
	}
	return nullptr;
}

template<typename T>
Node<T>* LinearSearchRecursive(Node<T>* first, T key)
{
	if (first == nullptr)
		return nullptr;
	
	if (key == first->m_data)
		first;
		
	else
		return LinearSearchRecursive(first->m_next, key);
}

template<typename T>
Node<T>* LinearSearchMoveToFrontOptimized(List<T>& list, T key)
{
	Node<T>* prev = nullptr;
	Node<T>* curr = list.begin();
	while (curr != nullptr)
	{
		if (key == curr->m_data)
		{
			prev->m_next = curr->m_next;
			curr->m_next = list.begin();
			list.m_head = curr;
			return curr;
		}

		prev = curr;
		curr = curr->m_next;
	}
	return nullptr;
}