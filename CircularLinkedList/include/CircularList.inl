#include <iostream>
#include <utility>

template <typename T>
class Node
{
private:

public:
	Node();
	Node(T value);
	Node(T value, Node<T>* next, Node<T>* prev);

	~Node();

	T m_data;
	Node<T>* m_next;
	Node<T>* m_prev;
};

template<typename T>
Node<T>::Node()
:
	m_data(T()),
	m_next(nullptr),
	m_prev(nullptr)
{

}

template <typename T>
Node<T>::Node(T value)
:
	m_data(value),
	m_next(nullptr),
	m_prev(nullptr)
{

}

template <typename T>
Node<T>::Node(T value, Node<T>* next, Node<T>* prev)
	:
	m_data(value),
	m_next(next),
	m_prev(prev)
{

}

template <typename T>
Node<T>::~Node()
{

}

template<typename T>
CircularList<T>::CircularList()
:
	m_size(0),
	m_head(nullptr),
	m_tail(nullptr)
{

}

template<typename T>
CircularList<T>::CircularList(T value)
:
	m_size(1),
	m_head(new Node<T>(value, m_head, m_head)),
	m_tail(nullptr)
{
	
}

template <typename T>
CircularList<T>::~CircularList()
{
	
}

template<typename T>
void CircularList<T>::pushBack(T value)
{
	Node<T>* temp = new Node<T>(value);
	Node<T>* last = begin();
	temp->m_next = last->m_next;
	last->m_next = temp;
	last = temp;
}