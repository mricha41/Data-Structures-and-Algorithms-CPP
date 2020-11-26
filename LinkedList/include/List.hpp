#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class Node;

template <typename T>
class List
{
public:
	List();
	List(T value);

	~List();

	//some algorithms need access to private
	//members and functions - SEE Algorithms.hpp
	//for the template function definitions
	template<typename T>
	friend Node<T>* LinearSearchMoveToFrontOptimized(List<T>& list, T key);

	//element access
	Node<T>*& begin() { return m_head; };
	Node<T>*& end() { return m_tail; };

	//modifiers
	void clear();
	void pushBack(T value);
	void pushFront(T value);
	void insert(std::size_t pos, T value);
	void sortedInsert(T value);
	T* popBack();
	T* popFront();
	bool erase(std::size_t pos);

	//capacity
	int length() { return m_size; };

	//operations
	void sort();
	bool isSorted();
	void unique();
	void reverse();
	void reverse(Node<T>* first, Node<T>* next);
	void concatenate(Node<T>* first, Node<T>* other, Node<T>* third);
	void merge(Node<T>* first, Node<T>* other, Node<T>* third);
	bool isLoop();

private:
	std::size_t m_size;
	Node<T>* m_head;
	Node<T>* m_tail;
};

#include "List.inl"

#endif //LIST_HPP