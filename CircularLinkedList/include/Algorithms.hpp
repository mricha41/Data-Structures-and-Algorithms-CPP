#include "CircularList.hpp"

#include <utility>

template<typename T>
void DisplayList(CircularList<T>& list)
{
	Node<T>* temp = list.begin();
	do
	{
		std::cout << temp->m_data << std::endl;
		temp = temp->m_next;
	} while (temp != list.begin() && temp != nullptr);
}

template<typename T>
void DisplayListRecursive(Node<T>* first)
{
	Node<T>* temp = first;
	bool flag = false;
	if ((temp != first || flag == false) && temp != nullptr)
	{
		flag != flag;
		std::cout << temp->m_data << std::endl;
		DisplayListRecursive(temp->m_next);
	}
}