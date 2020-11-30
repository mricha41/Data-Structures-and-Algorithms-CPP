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

	std::cout << "first length: " << first.length() << "\n";

	std::cout << "first..." << "\n";
	DisplayList(first);

	std::cout << "first recursive..." << "\n";
	DisplayListRecursive(first.begin());

	CircularList<mine> second(15.7f);
	second.pushFront(25.001f);
	second.pushFront(66.575f);
	second.pushFront(99.654f);
	second.pushFront(100.0f);
	second.pushFront(101.677f);

	std::cout << "second length: " << second.length() << "\n";

	std::cout << "second..." << "\n";
	DisplayList(second);

	std::cout << "second recursive..." << "\n";
	DisplayListRecursive(second.begin());
	
	CircularList<mine> third(15.7f);
	third.insert(1, 25.001f);
	third.insert(0, 66.575f);
	third.insert(3, 99.654f);
	third.insert(0, 100.0f);
	third.insert(5, 101.677f);

	std::cout << "third length: " << third.length() << "\n";

	std::cout << "third..." << "\n";
	DisplayList(third);

	std::cout << "third recursive..." << "\n";
	DisplayListRecursive(third.begin());

	CircularList<mine> test(15.7f);
	test.pushBack(33.f);
	test.pushBack(43.f);
	test.pushBack(73.f);
	test.pushBack(303.f);
	test.pushBack(133.f);

	std::cout << "length test: " << test.length() << "\n";

	DisplayList(test);

	test.clear();

	std::cout << "empty?" << "\n";
	DisplayList(test);

	return 0;
}