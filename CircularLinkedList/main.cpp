#include <iostream>
#include <string>

#include "CircularList.hpp"
#include "Algorithms.hpp"

typedef float mine;

int main()
{
	CircularList<mine> first(15.7f);
	first.pushBack(25.001f);
	first.pushBack(66.575f);
	first.pushBack(99.654f);
	first.pushBack(100.0f);
	first.pushBack(101.677f);

	std::cout << "first..." << "\n";
	DisplayList(first);

	std::cout << "first recursive..." << "\n";
	DisplayListRecursive(first.begin());
	
	return 0;
}