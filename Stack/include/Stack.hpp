#ifndef STACK_HPP
#define STACK_HPP

#include <tuple>
#include <initializer_list>

template <std::size_t stackSize, class C1>
class Stack
{
public:
	Stack();

	template <typename... T>
	Stack(T... elements);

	~Stack();

	//element access
	C1& top();
	C1& peek(std::size_t index);

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
	std::size_t m_top;
	C1 m_data[stackSize];
};

#include "Stack.inl"

#endif //STACK_HPP