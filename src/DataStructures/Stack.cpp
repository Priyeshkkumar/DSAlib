#include"Stack.h"

#ifdef STACK_USING_ARRAY

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

#endif

#ifdef STACK_USING_LINKEDLIST

bool Stack::SisEmpty() {
	if (Siterator == 0) {
		return true;
	}
	return false;
}

void Stack::Spush(int element) {
	head->SLL_add_front(element);
	Siterator++;
}

int Stack::Spop() {

	//#IMP: Why getting error when using if(head == nullptr)!!
	if (SisEmpty()) {
		std::cout << "\nStack Empty";
		return -1;
	}
	else {
		int element = head->SLL_GetHeadValue();
		head->SLL_delete_front();
		Siterator--;
		return element;
	}
}

void Stack::Display() {
	head->Display();
}

#endif