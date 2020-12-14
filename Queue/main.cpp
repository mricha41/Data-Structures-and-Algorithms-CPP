#include <iostream>

#include "Queue.hpp"
#include "Algorithms.hpp"

int main()
{
	Queue<10, int> queue;
	queue.push(10);
	std::cout << "front: " << queue.front() << "\n" << "back: " << queue.back() << "\n";
	queue.push(20);
	std::cout << "front: " << queue.front() << "\n" << "back: " << queue.back() << "\n";
	queue.push(30);
	std::cout << "front: " << queue.front() << "\n" << "back: " << queue.back() << "\n";
	queue.push(40);
	std::cout << "front: " << queue.front() << "\n" << "back: " << queue.back() << "\n";
	queue.push(50);
	std::cout << "front: " << queue.front() << "\n" << "back: " << queue.back() << "\n";

	Display(queue);

	std::cout << "popped: " << queue.pop() << "\n";
	std::cout << "popped: " << queue.pop() << "\n";

	Display(queue);

	std::cout << "popped: " << queue.pop() << "\n";
	std::cout << "popped: " << queue.pop() << "\n";
	std::cout << "popped: " << queue.pop() << "\n";

	queue.push(999);

	Display(queue);

	Queue<10, std::string> msgs = {"hola,", "mr.", "hand!"};
	std::cout << "front: " << msgs.front() << "\n" << "back: " << msgs.back() << "\n";

	Display(msgs);

	std::cout << "popped: " << msgs.pop() << "\n";

	Display(msgs);

	msgs.push("hola,");

	Display(msgs);

	msgs.pop();
	msgs.pop();
	msgs.pop();

	//Display(msgs); //will fail assert if uncommented

	msgs.push("hello, ");
	msgs.push("world!");

	std::cout << msgs.pop() << msgs.pop() << "\n";

	return 0;
}