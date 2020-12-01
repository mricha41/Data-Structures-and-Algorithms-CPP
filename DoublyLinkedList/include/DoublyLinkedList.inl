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
DoublyLinkedList<T>::DoublyLinkedList()
:
	m_size(0),
	m_head(nullptr),
	m_tail(nullptr)
{

}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T value)
:
	m_size(1),
	m_head(new Node<T>(value, nullptr, nullptr)),
	m_tail(nullptr)
{
	
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	
}

template<typename T>
void DoublyLinkedList<T>::pushBack(T value)
{
	Node<T>* newNode = new Node<T>(value, nullptr, nullptr);

	if (m_head == nullptr) {
		m_head = newNode;
		return;
	}

	Node<T>* curr = m_head;
	
	while (curr && curr->m_next) {
		curr = curr->m_next;
	}

	newNode->m_next = curr->m_next;
	newNode->m_prev = curr;
	curr->m_next = newNode;
	curr = newNode;

	m_size++;
}

template<typename T>
void DoublyLinkedList<T>::pushFront(T value)
{
	
}

template<typename T>
void DoublyLinkedList<T>::insert(std::size_t pos, T value)
{
	if (pos < 0 || pos > m_size)
		return;

	Node<T>* curr = m_head;
	Node<T>* newNode = new Node<T>(value, nullptr, nullptr);
	
	if (pos == 0)
	{
		newNode->m_next = m_head;
		m_head->m_prev = newNode;
		m_head = newNode;
	}
	else
	{
		for (std::size_t i = 0; i < pos - 1; ++i)
			curr = curr->m_next;

		newNode->m_prev = curr;
		newNode->m_next = curr->m_next;
		
		if (curr->m_next != nullptr)
			curr->m_next->m_prev = newNode;
		
		curr->m_next = newNode;
	}
	m_size++;
}

template <typename T>
bool DoublyLinkedList<T>::erase(std::size_t pos)
{
	return false;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	
}