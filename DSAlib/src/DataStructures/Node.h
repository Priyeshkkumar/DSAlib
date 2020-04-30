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
class Node_Two {
	int value;
	Node_Two* next;
	Node_Two* prev;
public:
	Node_Two() {
		value = 0;
		next = nullptr;
		prev = nullptr;
	}
	int GetNodeValue() {
		return value;
	}
	Node_Two* GetNodeNext() {
		return next;
	}
	Node_Two* GetNodePrev() {
		return prev;
	}
	void SetNodeValue(int vertex) {
		value = vertex;
	}
	void SetNodeNext(Node_Two* ptr) {
		next = ptr;
	}
	void SetNodePrev(Node_Two* ptr) {
		prev = ptr;
	}
};