#include"LinkedList.h"
#include<iostream>

//function definitions of singly linked list
void S_LinkedList::SLL_add_front(int element) {

	Node* temp = new Node;
	temp->SetNodeValue(element);

	if (head == NULL) {
		temp->SetNodeNext(nullptr);
	}
	else {
		temp->SetNodeNext(head);
	}
	head = temp;
}

void S_LinkedList::SLL_add_back(int element) {
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

void S_LinkedList::SLL_delete_front() {
	if (head == nullptr) {
		std::cout << "\nList is Empty!!";
	}
	else {
		Node* temp = head;
		head = head->GetNodeNext();
		delete temp;
	}
}

void S_LinkedList::SLL_delete_back() {
	if (head == nullptr) {
		std::cout << "\nList is Empty!!";
	}
	else if (head->GetNodeNext() == nullptr) {
		Node* temp = head;
		head = nullptr;
		delete temp;
	}
	else {
		Node* ptr = head;
		Node* prev = nullptr;
		while (ptr->GetNodeNext() != nullptr) {
			prev = ptr;
			ptr = ptr->GetNodeNext();
		}
		prev->SetNodeNext(nullptr);
		delete ptr;
	}
}

//Add checker if user provides a position greater than size of linked list::TODO
void S_LinkedList::SLL_delete_position(int position) {
	if (position - 1 == 0) {
		Node* temp = head;
		head = head->GetNodeNext();
		delete temp;
		return;
	}
	else {
		int i = 0;
		Node* ptr = head;
		Node* prev = nullptr;
		while (i != position - 1 && ptr != nullptr) {
			prev = ptr;
			ptr = ptr->GetNodeNext();
			++i;
		}
		if (ptr == nullptr) {
			std::cout << "Position Not found!!";
			return;
		}
		prev->SetNodeNext(nullptr);
		delete ptr;
	}
}

void S_LinkedList::SLL_delete_element(int element) {
	Node* ptr = head;
	if (head == nullptr) {
		std::cout << "List Empty!!";
		return;
	}
	if (head->GetNodeValue() == element) {
		head = head->GetNodeNext();
		delete ptr;
	}
	else {
		Node* prev = ptr;
		while (ptr != nullptr) {
			if (ptr->GetNodeValue() == element) {
				break;
			}
			prev = ptr;
			ptr = ptr->GetNodeNext();
		}
		if (ptr == nullptr) {
			std::cout << "No matching element!!";
			return;
		}
		prev->SetNodeNext(ptr->GetNodeNext());
		delete ptr;
	}
}
void S_LinkedList::Display() {
	Node* temp = head;
	std::cout << std::endl;
	if (temp == nullptr) {
		std::cout << "List is Empty!!";
	}
	else {
		while (temp) {
			std::cout << temp->GetNodeValue() << " ";
			temp = temp->GetNodeNext();
		}
	}
}


//function definitions of doubly linked list
void D_LinkedList::DLL_add_back(int element) {
	Node_Two* temp = new Node_Two;
	temp->SetNodeNext(nullptr);
	temp->SetNodePrev(nullptr);
	temp->SetNodeValue(element);
	if (head == NULL) {
		head = temp;
	}
	else {
		Node_Two* ptr = head;
		while (ptr->GetNodeNext() != nullptr) {
			ptr = ptr->GetNodeNext();
		}
		ptr->SetNodeNext(temp);
		temp->SetNodePrev(ptr);
	}
}

void D_LinkedList::DLL_add_front(int element) {
	Node_Two* temp = new Node_Two;
	temp->SetNodeNext(nullptr);
	temp->SetNodePrev(nullptr);
	temp->SetNodeValue(element);
	if (head == nullptr) {
		head = temp;
	}
	else {
		temp->SetNodeNext(head);
		head->SetNodePrev(temp);
	}
	head = temp;
}

void D_LinkedList::DLL_delete_front() {
	std::cout << std::endl;
	if (head == NULL) {
		std::cout << "\nList is empty!";
		return;
	}
	if (head->GetNodeNext() == nullptr) {
		Node_Two* temp = head;
		head = head->GetNodeNext();
		delete temp;
	}
	else {
		Node_Two* temp = head;
		head = head->GetNodeNext();
		head->SetNodePrev(nullptr);
		delete temp;
	}
}

void D_LinkedList::DLL_delete_back() {
	if (head == nullptr) {
		std::cout << "\nList is Empty!!";
		return;
	}
	else if(head->GetNodeNext() == nullptr) {
		Node_Two* temp = head;
		head = nullptr;
		delete temp;
	}
	else {
		Node_Two* ptr = head;
		while (ptr->GetNodeNext() != nullptr) {
			ptr = ptr->GetNodeNext();
		}
		Node_Two* prev = ptr->GetNodePrev();
		prev->SetNodeNext(nullptr);
		delete ptr;
	}
}

void D_LinkedList::DLL_delete_element(int element) {
	if (head == nullptr) {
		std::cout << "\nList is Empty!!";
		return;
	}
	if (head->GetNodeValue() == element) {
		Node_Two* temp = head;
		head = head->GetNodeNext();
		delete temp;
		return;
	}
	else {
		Node_Two* ptr = head;
		while (ptr && ptr->GetNodeValue() != element) {
			ptr = ptr->GetNodeNext();
		}
		if (ptr == nullptr) {
			std::cout << "Element not found!!";
			return;
		}
		Node_Two* prev = ptr->GetNodePrev();
		Node_Two* next = ptr->GetNodeNext();
		prev->SetNodeNext(next);
		delete ptr;
	}
}

void D_LinkedList::DLL_delete_position(int position) {
	if (head == nullptr) {
		std::cout << "\nList Empty!!";
		return;
	}
	if (position - 1 == 0) {
		Node_Two* temp = head;
		head = head->GetNodeNext();
		if (head != nullptr) {
			head->SetNodePrev(nullptr);
		}
		delete temp;
		return;
	}
	else {
		Node_Two* ptr = head;
		int i = 0;
		while (ptr && i != position - 1) {
			ptr = ptr->GetNodeNext();
			i++;
		}
		if (ptr == nullptr) {
			std::cout << "\nPosition not found!!";
			return;
		}
		if (ptr->GetNodeNext() == nullptr) {
			Node_Two* prev = ptr->GetNodePrev();
			prev->SetNodeNext(nullptr);
			delete ptr;
			return;
		}
		Node_Two* next = ptr->GetNodeNext();
		Node_Two* prev = ptr->GetNodePrev();
		prev->SetNodeNext(next);
		next->SetNodePrev(prev);
		delete ptr;
	}
}

void D_LinkedList::Display() {
	std::cout << std::endl;
	if (head == nullptr) {
		std::cout << "List is Empty!";
		return;
	}
	else {
		std::cout << "Traversing from front..\n";
		Node_Two* ptr = head;
		Node_Two* last = nullptr;
		while (ptr) {
			std::cout << ptr->GetNodeValue() << " ";
			last = ptr;
			ptr = ptr->GetNodeNext();
		}

		std::cout << std::endl << "Traversing from last...\n";
		while (last) {
			std::cout << last->GetNodeValue() << " ";
			last = last->GetNodePrev();
		}
	}
}