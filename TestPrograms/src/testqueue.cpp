#include<Queue.h>

int main() {
	Queue queue(5);
	queue.Qenqueue(1);
	queue.Qenqueue(2);
	queue.Qenqueue(3);
	queue.Qenqueue(4);
	queue.Qenqueue(5);

	QDisplay(queue);
}