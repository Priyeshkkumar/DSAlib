#pragma once
#include"Node.h"

class S_LinkedList {
	Node* head = nullptr;


public:
	S_LinkedList(){
		head = NULL;
	}


	//function to return node value of head
	int SLL_GetHeadValue() {
		return head->GetNodeValue();
	}
	//function to add element at back of linked list
	void SLL_add_back(int element);
	//function to add element at front of linked list
	void SLL_add_front(int element);
	//function to delete an element from front of list
	void SLL_delete_front();
	//function to delete an element from back of list
	void SLL_delete_back();
	//function to delete an element from between of list given position
	void SLL_delete_position(int position);
	//function to delete an element from between of list given element
	void SLL_delete_element(int element);
	//function to display linked list
	void Display();
	

	//Sorting Algorithms
	//1.SelectionSort - SelectionSort.cpp
	void SLL_SelectionSort();
	//2.Bubble Sort
	void SLL_BubbleSort();
		
	//functoion to 
	~S_LinkedList() {
		std::cout << std::endl << "Calling Destructor Singly Linked List...";
		Node* temp = nullptr;
		while (head) {
			temp = head;
			head = head->GetNodeNext();
			delete temp;
		}
		std::cout << std::endl << "Singly linked List Destructed!!"; 
	}
};

class D_LinkedList {
	Node_Two* head = nullptr;
public:
	D_LinkedList() {
		head = NULL;
	}
	//function to add element at back of linked list
	void DLL_add_back(int element);
	//function to add element at front of linked list
	void DLL_add_front(int element);
	//function to delete an element from front of list
	void DLL_delete_front();
	//function to delete an element from back of list
	void DLL_delete_back();
	//function to delete an element from between of list given position
	void DLL_delete_position(int position);
	//function to delete an element from between of list given element
	void DLL_delete_element(int element);
	//function to display linked list
	void Display();

	~D_LinkedList() {
		std::cout << std::endl << "Calling Destructor Doubly Linked List...";
		Node_Two* temp = nullptr;
		while (head) {
			temp = head;
			head = head->GetNodeNext();
			delete temp;
		}
		std::cout << std::endl << "Doubly linked List Destructed!!";
	}
};