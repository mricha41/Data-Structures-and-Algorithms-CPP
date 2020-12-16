#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP

template <typename T>
class Node;

template <typename T>
class QueueList
{
public:
	QueueList();
	QueueList(T value);

	~QueueList();

	//element access
	Node<T>*& front() { return m_front; };
	Node<T>*& back() { return m_back; };

	///capacity
	int size() { return m_size; };

	//operations
	void push(T value);
	T pop();

private:
	std::size_t m_size;
	Node<T>* m_front;
	Node<T>* m_back;
};

#include "QueueList.inl"

#endif //QUEUELIST_HPP