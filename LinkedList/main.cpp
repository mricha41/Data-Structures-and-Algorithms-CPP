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

	std::cout << "first..." << "\n";
	DisplayList(first);

	List<mine> second(50.f);
	second.pushBack(40.f);
	second.pushBack(10.f);
	second.pushBack(30.f);
	second.pushBack(20.f);

	std::cout << "second..." << "\n";
	DisplayList(second);

	List<mine> third;

	std::cout << "concatenation..." << "\n";
	first.concatenate(first.begin(), second.begin(), third.begin());

	std::cout << "first..." << "\n";
	DisplayList(first);

	std::cout << "second..." << "\n";
	DisplayList(second);

	std::cout << "third..." << "\n";
	DisplayList(third);

	third.pushBack(10.f);
	third.pushBack(20.f);
	third.pushBack(30.f);
	third.pushBack(40.f);
	third.pushBack(50.f);

	List<mine> fourth(5.f);
	fourth.pushBack(15.f);
	fourth.pushBack(25.f);
	fourth.pushBack(35.f);
	fourth.pushBack(45.f);

	List<mine> fifth;

	third.merge(third.begin(), fourth.begin(), fifth.begin());

	std::cout << "Merged into third: " << "\n";
	DisplayList(third);

	//works, but hangs console
	//if it is in fact looped
	/*std::cout << "looped? " << first.isLoop() << "\n";

	Node<mine>* t1 = first.begin()->m_next->m_next;
	Node<mine>* t2 = first.begin()->m_next->m_next->m_next->m_next;
	t2->m_next = t1;

	std::cout << "looped? " << first.isLoop() << "\n";*/
	
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

	List<mine> testUnique(10.f);
	testUnique.pushBack(10.f);
	testUnique.pushBack(10.f);
	testUnique.pushBack(10.f);

	DisplayList(testUnique);

	testUnique.unique();

	std::cout << "unique length: " << testUnique.length() << "\n";

	DisplayList(testUnique);

	first.reverse();

	DisplayList(first);

	first.reverse(nullptr, first.begin());

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