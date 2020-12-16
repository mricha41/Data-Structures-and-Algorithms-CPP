#include "QueueList.hpp"

#include <utility>

template<typename T>
void Display(QueueList<T>& list)
{
	assert((list.front() != nullptr) && "QueueList is empty!");

	Node<T>* temp = list.front();
	while (temp != nullptr)
	{
		std::cout << temp->m_data << "\n";
		temp = temp->m_next;
	}
}