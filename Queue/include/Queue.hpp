#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <tuple>
#include <initializer_list>

template <std::size_t queueSize, class C1>
class Queue
{
public:
	Queue();

	template <typename... T>
	Queue(T... elements);

	~Queue();

	//access for front and back indices
	//necessary for displaying queue
	template <std::size_t queueSize, class T1>
	friend void Display(Queue<queueSize, T1> queue);

	//element access
	C1& front();
	C1& back();

	C1& operator [] (std::size_t index);
	const C1& operator [] (std::size_t index) const;
	
	//modifiers
	void push(C1 value);
	C1 pop();

	//capacity
	std::size_t maxSize() { return m_maxSize; };
	std::size_t size() { return m_size; };

private:
	std::size_t m_maxSize;
	std::size_t m_size;
	std::size_t m_front;
	std::size_t m_back;
	C1 m_data[queueSize];
};

#include "Queue.inl"

#endif //QUEUE_HPP