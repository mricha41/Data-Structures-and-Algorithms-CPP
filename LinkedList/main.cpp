#include <iostream>
#include <string>

#include "List.hpp"
#include "Algorithms.hpp"

typedef float mine;

int main()
{
	List<mine> first(15.7f);
	first.pushBack(25.001f);
	first.pushBack(66.575f);
	first.pushBack(99.654f);
	first.pushBack(100.0f);
	first.pushBack(101.677f);

	std::cout << "Number of elements: " << first.length() << "\n";

	DisplayList(first);

	first.insert(0, 10.f);

	DisplayListRecursive(first.begin());

	first.sortedInsert(35.f);

	DisplayList(first);

	first.sortedInsert(500.f);

	DisplayList(first);

	std::cout << "Sorted? " << first.isSorted() << "\n";

	first.insert(0, 10000.f);

	DisplayList(first);

	std::cout << "Sorted? " << first.isSorted() << "\n";

	std::cout << "Erased? " << first.erase(first.length()) << "\n";

	DisplayList(first);

	std::cout << "Erased? " << first.erase(0) << "\n";

	DisplayList(first);

	std::cout << "Sorted? " << first.isSorted() << "\n";

	std::cout << "Erased? " << first.erase(1000) << "\n";

	first.pushFront(10.f);
	first.pushFront(10.f);
	first.pushBack(101.677f);
	first.pushBack(101.677f);

	DisplayList(first);

	first.unique();

	DisplayList(first);

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
	std::cout << "Found? " << (LinearSearch(first.begin(), 66.575f) == nullptr ? "no..." : "yes!") << "\n";

	std::cout << "Found? " << (LinearSearchRecursive(first.begin(), 25.f) == nullptr ? "no..." : "yes!") << "\n";
	std::cout << "Found? " << (LinearSearchRecursive(first.begin(), 66.575f) == nullptr ? "no..." : "yes!") << "\n";

	DisplayList(first);

	//list is unchanged after search...
	auto found = LinearSearchMoveToFrontOptimized(first, 25.f);
	std::cout << "Found? " << (found == nullptr ? "no..." : std::to_string(found->m_data)) << "\n";
	DisplayList(first);

	//list changes after search...
	found = LinearSearchMoveToFrontOptimized(first, 66.575f);
	std::cout << "Found? " << (found == nullptr ? "no..." : std::to_string(found->m_data)) << "\n";
	DisplayList(first);

	return 0;
}