#pragma once
#include"Node.h"

class LinkedList {
	Node* head;
public:
	LinkedList(){
		head = NULL;
	}

	//function to add element at back of linked list
	void LL_add_back(int element);
	//function to add element at front of linked list
	void LL_add_front(int element);
	//function to delete an element;
	int LL_delete(int element);
	//function to display linked list
	void Display();
};