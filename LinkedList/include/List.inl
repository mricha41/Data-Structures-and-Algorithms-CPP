#include "List.hpp"

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
	m_data(),
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
List<T>::List()
:
	m_size(0),
	m_head(nullptr),
	m_tail(nullptr)
{

}

template<typename T>
List<T>::List(T value)
:
	m_size(1),
	m_head(new Node<T>(value)),
	m_tail(nullptr)
{
	m_head->m_next = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
inline void List<T>::clear()
{
	Node<T>* prev = nullptr;
	//Node<T>* head = this->begin();
	while (m_head)
	{
		m_head = m_head->m_next;
		delete prev;
		prev = m_head;
	}
}

template<typename T>
void List<T>::pushBack(T value)
{
	Node<T>* newNode = new Node<T>(value);

	if (this->m_head == nullptr) {
		this->m_head = newNode;
		return;
	}

	Node<T>* curr = this->m_head;

	while (curr && curr->m_next) {
		curr = curr->m_next;
	}

	curr->m_next = newNode;

	m_size++;
}

template<typename T>
void List<T>::pushFront(T value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->m_next = m_head;
	m_head = newNode;
	m_size++;
}

template<typename T>
void List<T>::insert(std::size_t pos, T value)
{
	Node<T>* p = m_head;
	if (pos < 0 || pos > m_size)
		return;

	Node<T>* newNode = new Node<T>(value);
	if (pos == 0)
	{
		newNode->m_next = m_head;
		m_head = newNode;
	}
	else 
	{
		for (std::size_t i = 0; i < m_size - 1; ++i)
			p = p->m_next;

		newNode->m_next = p->m_next;
		p->m_next = newNode;
	}
}

template<typename T>
void List<T>::sortedInsert(T value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->m_next = nullptr;
	Node<T>* q = nullptr;
	Node<T>* p = m_head;

	if (m_head == nullptr)
		m_head = newNode;
	else
	{
		while (p && p->m_data < value)
		{
			q = p;
			p = p->m_next;
		}
		if (p == m_head)
		{
			newNode->m_next = m_head;
			m_head = newNode;
		}
		else
		{
			newNode->m_next = q->m_next;
			q->m_next = newNode;
		}
	}
}

template<typename T>
T* List<T>::popBack()
{
	return NULL;
}

template<typename T>
T* List<T>::popFront()
{
	return NULL;
}

template<typename T>
void List<T>::sort()
{
	return;
}

template<typename T>
bool List<T>::isSorted()
{
	Node<T>* temp = m_head;
	T v = std::numeric_limits<T>::min();

	while (temp != nullptr)
	{
		if (temp->m_data < v)
			return false;

		v = temp->m_data;
		temp = temp->m_next;
	}

	return true;
}