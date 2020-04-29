#include"LinkedList.h"
#include<iostream>

void LinkedList::LL_add_front(int element) {

	Node* temp = new Node;
	temp->SetNodeValue(element);

	if (head == NULL) {
		temp->SetNodeNext(nullptr);
	}
	else {
		temp->SetNodeValue(element);
	}
	head = temp;
}

void LinkedList::LL_add_back(int element) {
	Node* temp = new Node;
	temp->SetNodeNext(nullptr);
	temp->SetNodeValue(element);
	if (head == NULL) {
		head = temp;
	}
	else {
		Node* ptr = head;
		while (ptr->GetNodeNext() != nullptr) {
			ptr = ptr->GetNodeNext();
		}
		ptr->SetNodeNext(temp);
	}
}

void LinkedList::Display() {
	Node* temp = head;
	while (temp) {
		std::cout << temp->GetNodeValue() << " ";
		temp = temp->GetNodeNext();
	}
}