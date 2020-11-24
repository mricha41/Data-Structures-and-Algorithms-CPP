#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class Node;

template <typename T>
class List
{
private:
	void setHead(Node<T>*& n) { m_head = n; };
	void setTail(Node<T>*& n) { m_tail = n; };

public:
	List();
	List(T value);

	~List();

	//some algorithms need access to private
	//members and functions - SEE Algorithms.hpp
	//for the template function definitions
	template<typename T>
	friend Node<T>* LinearSearchMoveToFrontOptimized(List<T>& list, T key);

	Node<T>*& begin() { return m_head; };
	Node<T>*& end() { return m_tail; };

	void clear();

	void pushBack(T value);
	void pushFront(T value);
	T* popBack();
	T* popFront();

	int length() { return m_size; };

private:
	std::size_t m_size;
	Node<T>* m_head;
	Node<T>* m_tail;
};

#include "List.inl"

#endif //LIST_HPP