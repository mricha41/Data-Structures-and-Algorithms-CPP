#include <iostream>
#include <string>

#include "Stack.hpp"
#include "Algorithms.hpp"



int main()
{
	char* parens = const_cast<char*>("((a+b)*(c-d))");
	char* parens2 = const_cast<char*>("((((a+b)*(c-d)))/(t*t)-23/5*(PI)))");
	char* parens3 = const_cast<char*>("{int x[5] = {0}; for(int i=0; i<5; ++i) x[i] = i;}");
	//printf("parens length: %i\n", strlen(parens));

	std::cout << "match? " << MatchParenthesis<50>(parens) << "\n\n";
	std::cout << "match? " << MatchParenthesis<50>(parens2) << "\n\n";
	std::cout << "match? " << MatchParenthesis<50>(parens3) << "\n\n";

	char* infix = const_cast<char*>("a+b*c-d/e");
	char* postfix = infixToPostfix<5>(infix);

	std::cout << "postfix: " << postfix << "\n\n";

	return 0;
}