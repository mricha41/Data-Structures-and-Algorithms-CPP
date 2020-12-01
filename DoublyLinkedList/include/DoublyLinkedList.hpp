#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class Node;

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	DoublyLinkedList(T value);

	~DoublyLinkedList();

	//element access
	Node<T>*& begin() { return m_head; };
	Node<T>*& end() { return m_tail; };

	//modifiers
	void pushBack(T value);
	void pushFront(T value);
	void insert(std::size_t pos, T value);
	bool erase(std::size_t pos);
	void clear();

	//capacity
	int length() { return m_size; };

private:
	std::size_t m_size;
	Node<T>* m_head;
	Node<T>* m_tail;
};

#include "DoublyLinkedList.inl"

#endif //LIST_HPP