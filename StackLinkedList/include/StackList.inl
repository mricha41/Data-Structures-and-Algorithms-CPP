#include <iostream>
#include <utility>

template <typename T>
class Node
{
private:

public:
	Node();
	Node(T value);

	~Node();

	T m_data;
	Node<T>* m_next;
};

template<typename T>
Node<T>::Node()
:
	m_data(T()),
	m_next(nullptr)
{

}

template <typename T>
Node<T>::Node(T value)
:
	m_data(value),
	m_next(nullptr)
{

}

template <typename T>
Node<T>::~Node()
{

}

template<typename T>
StackList<T>::StackList()
:
	m_size(0),
	m_top(nullptr)
{

}

template<typename T>
StackList<T>::StackList(T value)
:
	m_size(1),
	m_top(new Node<T>(value))
{
	m_top->m_next = nullptr;
}

template <typename T>
StackList<T>::~StackList()
{
	
}

template <typename T>
void StackList<T>::push(T value)
{
	Node<T>* temp = new Node<T>(value);

	if (temp == nullptr)
		std::cout << "Stack is full!" << "\n";
	else
	{
		temp->m_next = m_top;
		m_top = temp;
		m_size++;
	}
}

template <typename T>
T StackList<T>::pop()
{
	T value = T();

	if (m_top == nullptr)
		std::cout << "Stack is empty!" << "\n";
	else
	{
		Node<T>* temp = m_top;
		m_top = m_top->m_next;
		value = temp->m_data;
		delete temp;
	}

	return value;
}