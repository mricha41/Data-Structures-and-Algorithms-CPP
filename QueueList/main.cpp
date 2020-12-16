#include <iostream>
#include <string>

#include "QueueList.hpp"
#include "Algorithms.hpp"

typedef float mine;

int main()
{
	QueueList<int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	Display(queue);

	std::cout << "\npopped: " << queue.pop() << "\n";

	Display(queue);

	std::cout << "\npopped: " << queue.pop() << "\n";
	std::cout << "popped: " << queue.pop() << "\n";
	
	Display(queue);
	
	std::cout << "\npopped: " << queue.pop() << "\n";
	std::cout << "popped: " << queue.pop() << "\n";
	//std::cout << "popped: " << queue.pop() << "\n";//fails assertion

	//Display(queue);//fails assertion

	QueueList<std::string> msgs("Hola, ");
	msgs.push("Mr. ");
	msgs.push("Hand!");

	Display(msgs);

	std::cout << "\n" << msgs.pop() << msgs.pop() << msgs.pop() << "\n";

	return 0;
}