#include <iostream>

#include "CircularQueue.hpp"
#include "Algorithms.hpp"

int main()
{
	CircularQueue<10, int> queue;// = { 10, 20, 30, 40, 50 };
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
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

	CircularQueue<10, std::string> msgs;
	msgs.push("hola, ");
	msgs.push("mr. ");
	msgs.push("hand!");
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
	msgs.push("there ");
	msgs.push("world!");

	Display(msgs);
	
	std::cout << msgs.pop() << msgs.pop() << msgs.pop() << "\n";
	
	return 0;
}