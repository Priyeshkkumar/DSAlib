#include"Queue.h"

bool Queue::Qisfull() {
	if (Qrear == Qfront && Qiterator >= Qsize)
		return true;

	return false;
}

bool Queue::QisEmpty() {
	if (Qrear == Qfront)
		return true;

	return false;
}
void  Queue::Qenqueue(int value) {
	if (Qisfull()) {
		std::cout << "Queue is full!";
		exit(0);
	}
	Qiterator++;
	Qarr[Qrear] = value;
	Qrear = (Qrear + 1);
}

int Queue::Qdequeue() {
	if (QisEmpty()) {
		std::cout << "Queue is Empty!";
		return 0;
	}
	int temp;
	temp = Qarr[Qfront];
	Qiterator--;
	Qfront = (Qfront+1);
	return temp;
}

void QDisplay(Queue queue) {
	if (queue.QisEmpty()) {
		std::cout << "Queue is Empty!";
		return;
	}
	std::cout << "Queue:\n";
	for (int i = 0; i < queue.QGetSize(); ++i) {
		std::cout << queue.Qdequeue() << " ";
	}
}