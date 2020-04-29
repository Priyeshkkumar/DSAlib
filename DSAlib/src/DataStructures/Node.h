#pragma once
#include<iostream>

//A Class to represent a node with a single pointer to pointing to next node...
class Node {
	int value;
	Node* next;
public:
	Node() {
		value = NULL;
		next = nullptr;
	}
	int GetNodeValue() {
		return value;
	}
	Node* GetNodeNext() {
		return next;
	}
	void SetNodeValue(int vertex) {
		value = vertex;
	}
	void SetNodeNext(Node* ptr) {
		next = ptr;
	}
};


//A class which inherits form Node class to extend it's functionality  
//for support of two pointers pointing to next and previous nodes...
class Node_With_Prev : public Node {
	Node* prev;
public:
	Node_With_Prev() {
		prev = nullptr;
	}
	Node* GetNodePrev() {
		return prev;
	}
	void SetNodePrev(Node* ptr) {
		prev = ptr;
	}
};