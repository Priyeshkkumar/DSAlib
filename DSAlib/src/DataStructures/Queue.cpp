#include"Queue.h"


#ifdef QUEUE_USING_ARRAY

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

#endif

#ifdef QUEUE_USING_LINKEDLIST

bool Queue::QisEmpty() {
	if (Qiterator == 0) {
		return true;
	}
	return false;
}

void Queue::Qenqueue(int element) {
	head->SLL_add_back(element);
	Qiterator++;
}

int Queue::Qdequeue() {
	if (QisEmpty()) {
		std::cout << "\nQueue is empty";
		return -1;
	}
	else {
		int element = head->SLL_GetHeadValue();
		head->SLL_delete_front();
		Qiterator--;
		return element;
	}
}

void Queue::Display() {
	head->Display();
}
#endif