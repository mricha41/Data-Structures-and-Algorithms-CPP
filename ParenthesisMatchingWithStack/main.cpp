#include <iostream>
#include <string>

#include "Stack.hpp"
#include "Algorithms.hpp"

int main()
{
	Stack<25, std::string> test;
	test.push("hello");
	test.push("world");
	test.push("hola");
	test.push("mr.");
	test.push("hand");
	
	Display(test);
	
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

	char* parens = const_cast<char*>("((a+b)*(c-d))");
	char* parens2 = const_cast<char*>("((((a+b)*(c-d)))/(t*t)-23/5*(PI)))");
	//printf("parens length: %i\n", strlen(parens));

	std::cout << "match? " << MatchParenthesis<50>(parens) << "\n\n";
	std::cout << "match? " << MatchParenthesis<50>(parens2) << "\n\n";

	return 0;
}