#include "DoublyLinkedList.hpp"

#include <utility>

template<typename T>
void DisplayList(DoublyLinkedList<T>& list)
{
	if (list.length() < 1)
		return;

	Node<T>* temp = list.begin();
	while(temp != nullptr)
	{
		std::cout << temp->m_data << std::endl;
		temp = temp->m_next;
	}
}

template<typename T>
void DisplayListRecursive(Node<T>* first)
{
	if (first != nullptr)
	{
		std::cout << first->m_data << std::endl;
		DisplayListRecursive(first->m_next);
	}
}