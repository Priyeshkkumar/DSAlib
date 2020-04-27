#include"Stack.h"

bool Stack::SisFull() {
	if (Siterator == Ssize) {
		return true;
	}
	return false;
}

bool Stack::SisEmpty() {
	if (Siterator == 0) {
		return true;
	}
	return false;
}

void Stack::Spush(int value) {
	if (SisFull()) {
		std::cout << "\nStack is full";
		exit(0);
	}
	Sarr[Siterator] = value;
	Siterator++;
}

int Stack::Spop() {
	if (SisEmpty()) {
		std::cout << "\nStack is Empty!";
		return 0;
	}
	int temp;
	int index = Siterator - 1;
	temp = Sarr[index];
	Siterator--;
	return temp;
}

int Stack::Stop() {
	if (SisEmpty()) {
		std::cout << "Stack is Empty!";
		return 0;
	}
	int temp;
	int index = Siterator - 1;
	temp = Sarr[index];
	return temp;

}