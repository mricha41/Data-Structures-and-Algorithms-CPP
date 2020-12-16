#include <iostream>
#include <cassert>

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
QueueList<T>::QueueList()
:
	m_size(0),
	m_front(nullptr),
	m_back(nullptr)
{

}

template<typename T>
QueueList<T>::QueueList(T value)
:
	m_size(1),
	m_front(new Node<T>(value)),
	m_back(m_front)
{
	m_front->m_next = nullptr;
	m_back->m_next = nullptr;
}

template <typename T>
QueueList<T>::~QueueList()
{
	
}

template <typename T>
void QueueList<T>::push(T value)
{
	auto temp = new Node<T>(value);
	assert((temp != nullptr) && "Pushed an invalid value onto the QueueList!");

	temp->m_next = nullptr;
	if (m_front == nullptr)
		m_front = m_back = temp;
	else
	{
		if(m_back != nullptr)
			m_back->m_next = temp;
		m_back = temp;
	}

	m_size++;
}

template <typename T>
T QueueList<T>::pop()
{
	assert((m_front != nullptr) && "QueueList is empty!");

	T popped = T();
	Node<T>* temp;

	popped = m_front->m_data;
	temp = m_front;
	m_front = m_front->m_next;
	delete temp;

	m_size--;

	return popped;
}