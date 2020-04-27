#pragma once
#include<iostream>
#include<math.h>

class Min_Heap
{
	int heap_capacity;
	int heap_elements;
	int* heap_arr;
public:
	Min_Heap() = delete;
	Min_Heap(int capacity) {
		heap_capacity = capacity;
		heap_elements = 0;
		heap_arr = new int[heap_capacity];
	}

	//function to return parent
	int MinH_get_parent(int index) {
		return ((index-1) / 2);	
	}
	//function to return left child
	int MinH_left_child(int index) {
		return (2 * index + 1);
	}
	//function to return right child
	int MinH_right_child(int index) {
		return (2 * index + 2);
	}
	//function to insert elements in min heap
	void MinH_Insert(int element);

	//function to min heapify the heap
	void MinH_Heapify(int index);

	//function to extract min element
	int MinH_ExtractMin();

	//function to display heap
	void Display();

	~Min_Heap() {
		delete[] heap_arr;
	}
};

class Max_Heap {
	int heap_capacity;
	int heap_elements;
	int* heap_arr;
public:
	Max_Heap() = delete;
	Max_Heap(int capacity) {
		heap_capacity = capacity;
		heap_elements = 0;
		heap_arr = new int[heap_capacity];
	}
	//function to return parent of element
	int MaxH_get_parent(int index) {
		return (index - 1) / 2;
	}
	//function to return left child
	int MaxH_left_child(int index) {
		return (2 * index) + 1;
	}
	//function to return right child
	int MaxH_right_child(int index) {
		return (2 * index) + 2;
	}
	//function to insert new element in heap;
	void MaxH_Insert(int element);

	//function to extract max element
	int MaxH_ExtractMax();

	//functio to max heapify
	void MaxH_Heapify(int index);

	//function to display heap
	void Display();

	~Max_Heap() {
		delete[] heap_arr;
	}
};

