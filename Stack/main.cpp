#include <iostream>

#include "Stack.hpp"
#include "Algorithms.hpp"

int main()
{
	Stack<10, int> mystack = {10, 1, 6, 20, 5};

	Display(mystack);

	std::cout << "Peek at the top of stack: " << mystack.top() << "\n\n";

	mystack.push(128);

	Display(mystack);

	std::cout << "Peek at the top of stack: " << mystack.top() << "\n\n";

	mystack.pop();

	Display(mystack);

	std::cout << "Peek at the top of stack: " << mystack.top() << "\n\n";

	Stack<5, int> test = {};
	test.push(10);
	test.push(20);
	test.push(30);
	test.push(40);
	test.push(50);

	Display(test);

	std::cout << "Peek at the top of stack: " << test.top() << "\n\n";

	return 0;
}