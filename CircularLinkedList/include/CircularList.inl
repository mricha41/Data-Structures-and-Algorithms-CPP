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
Node<T>::Node(T value, Node<T>* next, Node<T>* prev)
	:
	m_data(value),
	m_next(next)
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
	m_head(new Node<T>(value)),
	m_tail(nullptr)
{
	
}

template <typename T>
CircularList<T>::~CircularList()
{
	clear();
}

template<typename T>
void CircularList<T>::pushBack(T value)
{
	Node<T>* newNode = new Node<T>(value);

	if (this->m_head == nullptr) {
		this->m_head = newNode;
		m_size++;
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
void CircularList<T>::pushFront(T value)
{
	Node<T>* newNode = new Node<T>(value);
	if (m_head == nullptr)
	{
		m_head = newNode;
		m_head->m_next = m_head;
	}
	else
	{
		Node<T>* curr = m_head;

		while (curr != nullptr && curr->m_next != m_head)
			curr = curr->m_next;
		
		if(curr != nullptr)
			curr->m_next = newNode;
		
		newNode->m_next = m_head;
		m_head = newNode;
	}
	m_size++;
}

template<typename T>
void CircularList<T>::insert(std::size_t pos, T value)
{
	Node<T>* curr = m_head;
	if (pos < 0 || pos > m_size)
		return;

	Node<T>* newNode = new Node<T>(value);
	if (pos == 0)
	{
		if (m_head == nullptr)
		{
			m_head = newNode;
			m_head->m_next = m_head;
		}
		else
		{
			while (curr != nullptr && curr->m_next != m_head)
				curr = curr->m_next;

			if(curr != nullptr)
				curr->m_next = newNode;
			
			newNode->m_next = m_head;
			m_head = newNode;
		}
	}
	else
	{
		for (std::size_t i = 0; i < pos - 1; ++i)
			curr = curr->m_next;

		newNode->m_next = curr->m_next;
		curr->m_next = newNode;
	}
	m_size++;
}

template <typename T>
bool CircularList<T>::erase(std::size_t pos)
{

	Node<T>* temp = nullptr;
	Node<T>* curr = m_head;

	if (pos < 0 || pos > m_size)
		return false;

	if (pos == 0)
	{
		temp = m_head;
		m_head = m_head->m_next;
		delete temp;
		m_size--;
	}
	else
	{
		for (std::size_t i = 0; i < m_size - 1; ++i)
		{
			temp = curr;
			curr = curr->m_next;
		}

		if (temp != nullptr)
			temp->m_next = curr->m_next;

		delete curr;
		m_size--;
	}
	return true;
}

template <typename T>
void CircularList<T>::clear()
{
	if (m_head == nullptr)
		return;

	Node<T>* prev = nullptr;

	while (m_head != nullptr)
	{
		m_head = m_head->m_next;
		if (prev != nullptr)
		{
			delete prev;
			prev = m_head;
		}
	}
	m_size = 0;
}