#include <iostream>
#include <string>

#include "List.hpp"
#include "Algorithms.hpp"

typedef float mine;

int main()
{
	List<mine> first(15.7f);
	first.pushBack(25.001f);
	first.pushFront(666.575f);
	first.pushBack(-99.654f);
	first.pushFront(0.0f);
	first.pushBack(101.677f);

	std::cout << "Number of elements: " << first.length() << "\n";

	DisplayList(first);

	DisplayListRecursive(first.begin());

	std::cout << "Sum: " << Sum(first) << "\n";
	std::cout << "Sum recursive: " << SumRecursive(first.begin()) << "\n";

	std::cout << "Max: " << Max(first) << "\n";
	std::cout << "Min: " << Min(first) << "\n";

	std::cout << "Max recursive: " << MaxRecursive(first.begin()) << "\n";
	std::cout << "Min recursive: " << MinRecursive(first.begin()) << "\n";

	auto p = std::pair<float, float>(MinMax(first));
	auto pr = std::pair<float, float>(MinMaxRecursive(first));

	std::cout << "Min/Max: " << p.first << ", " << p.second << "\n";
	std::cout << "Min/Max recursive: " << pr.first << ", " << pr.second << "\n";

	std::cout << "Found? " << (LinearSearch(first.begin(), 25.f) == nullptr ? "no..." : "yes!") << "\n";
	std::cout << "Found? " << (LinearSearch(first.begin(), 666.575f) == nullptr ? "no..." : "yes!") << "\n";

	std::cout << "Found? " << (LinearSearchRecursive(first.begin(), 25.f) == nullptr ? "no..." : "yes!") << "\n";
	std::cout << "Found? " << (LinearSearchRecursive(first.begin(), 666.575f) == nullptr ? "no..." : "yes!") << "\n";

	DisplayList(first);

	//list is unchanged after search...
	std::cout << "Found? " << (LinearSearchMoveToFrontOptimized(first, 25.f) == nullptr ? "no..." : "yes!") << "\n";
	DisplayList(first);

	//list changes after search...
	auto found = LinearSearchMoveToFrontOptimized(first, 666.575f);
	std::cout << "Found? " << (found == nullptr ? "no..." : std::to_string(found->m_data)) << "\n";
	DisplayList(first);

	return 0;
}