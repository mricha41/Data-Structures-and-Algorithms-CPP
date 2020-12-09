#include <iostream>

#include "StackList.hpp"
#include "Algorithms.hpp"

int main()
{
	StackList<int> test;
	test.push(10);
	test.push(20);
	test.push(30);
	test.push(40);
	test.push(50);

	std::cout << "Top StackList value: " << test.top()->m_data << "\n\n";

	Display(test);

	std::cout << "Popped value: " << test.pop() << "\n\n";
	std::cout << "Popped value: " << test.pop() << "\n\n";

	Display(test);

	return 0;
}