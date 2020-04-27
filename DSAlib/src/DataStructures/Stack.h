#pragma once
#include<iostream>

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