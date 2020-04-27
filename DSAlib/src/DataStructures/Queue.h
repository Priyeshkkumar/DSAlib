#pragma once
#include<iostream>

class Queue {
	int Qsize, Qfront, Qrear, Qiterator;
	int* Qarr;
public:
	Queue(int size) {
		std::cout << "\nInside Queue!";
		Qsize = size;
		Qfront = Qiterator = Qrear = 0;
		Qarr = new int[Qsize];
	}
	int QGetFront() {
		return Qfront;
	}
	int QGetRear() {
		return Qrear;
	}
	int QGetSize(){
		return Qsize;
	}
	int* QGetArr() {
		return Qarr;
	}
	//function to check wheter queue is full
	bool Qisfull();
	//function to check wheter queue is empty
	bool QisEmpty();

	//function to add item to queue
	void Qenqueue(int value);
	//function to remove item to queue
	int Qdequeue();

	~Queue() {
		std::cout << "\nDestructor Queue!!";
		delete[] Qarr;
	}
};

void QDisplay(Queue queue);
 