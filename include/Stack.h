#pragma once
#include"LinkedList.h"
#include<iostream>

#define STACK_USING_LINKEDLIST
//#define STACK_USING_ARRAY


#ifdef STACK_USING_ARRAY
class Stack {
	int Ssize, Siterator;
	int* Sarr;
public:
	Stack(int size) {
		std::cout << "\nInside Stack!";
		Ssize = size;
		Siterator = 0;
		Sarr = new int[Ssize];
	}
	int SGetSize() {
		return Ssize;
	}
	int* SGetArr() {
		return Sarr;
	}
	//function to check if stack is full
	bool SisFull();
	//function to check if stack is empty
	bool SisEmpty();
	//function to push an item
	void Spush(int value);
	//function to pop an item
	int Spop();
	//function that returns value of top of stack
	int Stop();
	~Stack() {
		std::cout << "\nDestructor Stack";
		delete[] Sarr;
	}
};
#endif

#ifdef STACK_USING_LINKEDLIST
class Stack {
	int  Siterator;
	S_LinkedList* head;
public:
	//since uisng linked lists therefore not adding a size factor
	Stack() {
		std::cout << "\nInside Stack!";
		Siterator = 0;
		head = new S_LinkedList;
	}
	S_LinkedList* SGetHead() {
		return head;
	}
	//function to check if stack is empty
	bool SisEmpty();
	//function to push an item
	void Spush(int value);
	//function to pop an item
	int Spop();
	//function that returns value of top of stack
	int Stop();
	//function to display all elements of stack
	void Display();
	~Stack() {
		std::cout << "\nDestructor Stack";
		delete head;
	}
};
#endif