#include<Queue.h>

int main() {
	Queue queue;
	queue.Qenqueue(1);
	queue.Qenqueue(2);
	queue.Qenqueue(3);
	queue.Qenqueue(4);
	queue.Qenqueue(5);

	queue.Display();

	int element;
	element = queue.Qdequeue();
	std::cout << std::endl << element;
	element = queue.Qdequeue();
	std::cout << std::endl << element;
	element = queue.Qdequeue();
	std::cout << std::endl << element;
	element = queue.Qdequeue();
	std::cout << std::endl << element;
	element = queue.Qdequeue();
	std::cout << std::endl << element;
	element = queue.Qdequeue();
	std::cout << std::endl << element;
}