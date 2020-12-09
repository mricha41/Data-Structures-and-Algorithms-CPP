#ifndef STACKLIST_HPP
#define STACKLIST_HPP

template <typename T>
class Node;

template <typename T>
class StackList
{
public:
	StackList();
	StackList(T value);

	~StackList();

	//element access
	Node<T>*& top() { return m_top; };
	
	//modifiers
	void push(T value);
	T pop();
	
	//capacity
	
	//operations

private:
	std::size_t m_size;
	Node<T>* m_top;
};

#include "StackList.inl"

#endif //STACKLIST_HPP