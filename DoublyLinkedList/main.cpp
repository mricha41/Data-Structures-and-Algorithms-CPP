#include <iostream>
#include <string>

#include "DoublyLinkedList.hpp"
#include "Algorithms.hpp"

typedef float mine;

int main()
{
	DoublyLinkedList<mine> first(10.f);
	first.pushBack(20.f);
	first.pushBack(30.f);
	first.pushBack(40.f);
	first.pushBack(50.f);

	std::cout << "first length: " << first.length() << "\n";

	std::cout << "first..." << "\n";
	DisplayList(first);

	first.insert(2, 25.f);
	first.insert(6, 55.f);
	first.insert(0, 5.f);

	std::cout << "first after insert..." << "\n";
	DisplayList(first);

	first.erase(0);
	first.erase(6);
	first.erase(2);

	std::cout << "first after erase..." << "\n";
	DisplayList(first);

	first.reverse();

	std::cout << "first after reverse..." << "\n";
	DisplayList(first);

	return 0;
}