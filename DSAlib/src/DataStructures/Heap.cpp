#include"Heap.h"

void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}


//Min Heap functions..


void Min_Heap::MinH_Heapify(int index) {
	int left_child_index = MinH_left_child(index);
	int right_child_index = MinH_right_child(index);
	int smallest = index;//index pointing the smallest number

	//check for min heap conditions;
	if (left_child_index < heap_elements && heap_arr[left_child_index] < heap_arr[smallest]) {
		smallest = left_child_index;
	}
	if (right_child_index < heap_elements && heap_arr[right_child_index] < heap_arr[smallest]) {
		smallest = right_child_index;
	}
	if (smallest != index) {
		swap(heap_arr[smallest], heap_arr[index]);
		MinH_Heapify(smallest);
	}
	else {
		return;
	}
}

void Min_Heap::MinH_Insert(int element) {
	if (heap_capacity == heap_elements) {
		std::cout << "Overflow, Heap Full!!";
		exit(0);
	}
	else {
		if (heap_elements == 0) {
			heap_arr[0] = element;
			heap_elements++;
		}
		else {
			int current_index = heap_elements;
			heap_arr[current_index] = element;
			heap_elements++;
			int parent_index = MinH_get_parent(current_index);
			while (parent_index >= 0 && heap_arr[parent_index] > heap_arr[current_index]) {
					swap(heap_arr[parent_index], heap_arr[current_index]);
					current_index = parent_index;
					parent_index = MinH_get_parent(parent_index);
			}
		}
	}
}

int Min_Heap::MinH_ExtractMin() {
	if (heap_elements <= 0) {
		std::cout << "Undeflow, returning -1";
		return -1;
	}
	else if (heap_elements == 1) {
		heap_elements--;
		return heap_arr[0];
	}
	else {
		int root = heap_arr[0];
		heap_arr[0] = heap_arr[heap_elements-1];
		heap_elements--;
		MinH_Heapify(0);
		return root;
	}
}

void Min_Heap::Display() {
		for (int i = 0; i < heap_elements; ++i) {
			std::cout << heap_arr[i] << " ";
		}
		std::cout << std::endl;
}


//Max Heap functions


void Max_Heap::Display() {
	for (int i = 0; i < heap_elements; ++i) {
		std::cout << heap_arr[i] << " ";
	}
	std::cout << std::endl;
}

void Max_Heap::MaxH_Insert(int element) {
	if (heap_elements == heap_capacity) {
		std::cout << "Overflow! Heap full!!";
		exit(0);
	}
	else {
		if (heap_elements == 0) {
			heap_arr[0] = element;
			heap_elements++;
		}
		else {
			int current_index = heap_elements;
			int parent_index = MaxH_get_parent(current_index);
			heap_arr[current_index] = element;
			heap_elements++;
			while (parent_index >= 0 && heap_arr[parent_index] < heap_arr[current_index]) {
				swap(heap_arr[parent_index], heap_arr[current_index]);
				current_index = parent_index;
				parent_index = MaxH_get_parent(parent_index);
			}
		}
	}
}

void Max_Heap::MaxH_Heapify(int index) {
	int left_child_index = MaxH_left_child(index);
	int right_child_index = MaxH_right_child(index);
	int largest = index;

	//check for max heap conditions
	if (left_child_index < heap_elements && heap_arr[left_child_index] > heap_arr[largest]) {
		largest = left_child_index;
	}
	if (right_child_index < heap_elements && heap_arr[right_child_index]>heap_arr[largest]) {
		largest = right_child_index;
	}
	if (largest != index) {
		swap(heap_arr[largest], heap_arr[index]);
		MaxH_Heapify(largest);
	}
}

int Max_Heap::MaxH_ExtractMax() {
	if (heap_elements <= 0) {
		std::cout << "Undeflow, Heap Empty!!";
		return -1;
	}
	else {
		if (heap_elements == 1) {
			heap_elements--;
			return heap_arr[0];
		}
		else {
			int root = heap_arr[heap_elements];
			heap_arr[0] = heap_arr[heap_elements - 1];
			heap_elements--;
			MaxH_Heapify(0);
			return root;
		}
	}
}