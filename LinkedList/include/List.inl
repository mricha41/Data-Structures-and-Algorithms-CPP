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
void List<T>::clear()
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
	Node<T>* curr = m_head;
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
			curr = curr->m_next;

		newNode->m_next = curr->m_next;
		curr->m_next = newNode;
	}
	m_size++;
}

template<typename T>
void List<T>::sortedInsert(T value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->m_next = nullptr;
	Node<T>* temp = nullptr;
	Node<T>* curr = m_head;

	if (m_head == nullptr)
		m_head = newNode;
	else
	{
		while (curr && curr->m_data < value)
		{
			temp = curr;
			curr = curr->m_next;
		}
		if (curr == m_head)
		{
			newNode->m_next = m_head;
			m_head = newNode;
		}
		else
		{
			newNode->m_next = temp->m_next;
			temp->m_next = newNode;
		}
		m_size++;
	}
}

template<typename T>
T* List<T>::popBack()
{
	return nullptr;
}

template<typename T>
T* List<T>::popFront()
{
	return nullptr;
}

template<typename T>
bool List<T>::erase(std::size_t pos)
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
		
		if(temp != nullptr)
			temp->m_next = curr->m_next;
		
		delete curr;
		m_size--;
	}
	return true;
}

//count is a useful when a
//modifying operation results
//in a necessary change to the length
//of the list
template<typename T>
std::size_t List<T>::count()
{
	std::size_t count = 0;
	Node<T>* curr = m_head;
	while (curr != nullptr)
	{
		count++;
		curr = curr->m_next;
	}

	return count;
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

template<typename T>
void List<T>::unique()
{
	Node<T>* temp = nullptr;
	Node<T>* curr = m_head;
	if(curr != nullptr && curr->m_next != nullptr)
		temp = curr->m_next;

	while (temp != nullptr)
	{
		if (curr->m_data != temp->m_data)
		{
			curr = temp;
			temp = temp->m_next;
		}
		else
		{
			curr->m_next = temp->m_next;
			delete temp;
			temp = curr->m_next;
		}
	}

	//reset the internal size
	//...but need to count to see what it is
	m_size = count();
}

template<typename T>
void List<T>::reverse()
{
	Node<T>* temp = nullptr;
	Node<T>* temp2 = nullptr;
	Node<T>* curr = m_head;

	while (curr != nullptr)
	{
		temp2 = temp;
		temp = curr;
		curr = curr->m_next;
		temp->m_next = temp2;
	}
	m_head = temp;
}

template<typename T>
void List<T>::reverse(Node<T>* first, Node<T>* next)
{
	if (next != nullptr)
	{
		reverse(next, next->m_next);
		next->m_next = first;
	}
	else
	{
		m_head = first;
	}
}

template<typename T>
void List<T>::concatenate(Node<T>* first, Node<T>* other, Node<T>* third)
{
	third = first;

	while (first->m_next != nullptr)
	{
		first = first->m_next;
		m_size++;
	}
	
	first->m_next = other;
}

template<typename T>
void List<T>::merge(Node<T>* first, Node<T>* other, Node<T>* third)
{
	Node<T>* last;
	if (first->m_data < other->m_data)
	{
		third = last = first;
		first = first->m_next;
		third->m_next = nullptr;
	}
	else
	{
		third = last = other;
		other = other->m_next;
		third->m_next = nullptr;
	}
	
	while (first != nullptr && other != nullptr)
	{
		if (first->m_data < other->m_data)
		{
			last->m_next = first;
			last = first;
			first = first->m_next;
			last->m_next = nullptr;
		}
		else
		{
			last->m_next = other;
			last = other;
			other = other->m_next;
			last->m_next = nullptr;
		}
	}

	if (first != nullptr)
		last->m_next = first;
	if (other != nullptr)
		last->m_next = other;
}

template<typename T>
bool List<T>::isLoop()
{
	Node<T>* p = nullptr, * q =  nullptr, * first = m_head;
	p = q = first;
	do
	{
		p = p->m_next;
		q = q->m_next;
		q = q ? q->m_next : q;
	} while (p && q && p != q);

	if (p == q)
		return true;

	return false;
}