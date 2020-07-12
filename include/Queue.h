#pragma once
#include<iostream>
#include"LinkedList.h"

//define QUEUE_USING_ARRAY
#define QUEUE_USING_LINKEDLIST

#ifdef QUEUE_USING_ARRAY

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

#endif


#ifdef QUEUE_USING_LINKEDLIST

class Queue {
	int Qiterator;
	S_LinkedList* head;
public:
	//using linked lists therefore not adding a size factor
	Queue() {
		std::cout << "\nInside Queue!";
		Qiterator = 0;
		head = new S_LinkedList;
	}
	//function to check wheter queue is empty
	bool QisEmpty();
	//function to add item to queue
	void Qenqueue(int value);
	//function to remove item to queue
	int Qdequeue();

	void Display();

	~Queue() {
		std::cout << "\nDestructor Queue!!";
		delete head;
	}
};

void QDisplay(Queue queue);

#endif