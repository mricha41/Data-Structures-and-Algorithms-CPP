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

	Stack<25, int> test;
	//Stack<250000, int> test;
	std::cout << "Peek at the top of stack: " << test.top() << "\n\n";
	/*for (std::size_t i = 0; i < 250000; ++i)
		test.push(i % 10);*/
	test.push(10);
	test.push(20);
	test.push(30);
	test.push(40);
	test.push(50);
	test.push(60);
	test.push(70);
	test.push(80);

	Display(test);
	/*for (std::size_t i = 0; i < 250000; ++i)
		printf("%i ", test[i]);
	printf("\n");*/

	std::cout << "Peek at the top of stack: " << test.top() << "\n\n";

	std::cout << "Peek at index in stack: " << test.peek(2) << "\n\n";
	//std::cout << "Peek at index in stack: " << test.peek(-1) << "\n\n";
	std::cout << "Peek at index in stack: " << test.peek(0) << "\n\n";
	std::cout << "Peek at index in stack: " << test.peek(4) << "\n\n";
	//std::cout << "Peek at index in stack: " << test.peek(5) << "\n\n";
	//std::cout << "Peek at index in stack: " << test.peek(11) << "\n\n";

	std::cout << "Popped off stack: " << test.pop() << "\n\n";

	//std::cout << "Peek at index in stack: " << test.peek(4) << "\n\n";

	Display(test);

	return 0;
}