#include "StackList.hpp"

#include <utility>

template<typename T>
void Display(StackList<T>& list)
{
	Node<T>* temp = list.top();
	while (temp != nullptr)
	{
		std::cout << temp->m_data << "\n";
		temp = temp->m_next;
	}
	std::cout << "\n";
}