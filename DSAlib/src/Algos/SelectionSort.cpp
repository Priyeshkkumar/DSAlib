#include"Algos.h"

void swap_sorting(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_sorting(Node* a, Node* b) {
	int temp = a->GetNodeValue();
	a->SetNodeValue(b->GetNodeValue());
	b->SetNodeValue(temp);
}
//Selection Sort for array
void SelectionSort(int* ptr, int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		int min_index = i;
		for (j = i+1; j < size; ++j) {
			if (ptr[min_index] > ptr[j]) {
				min_index = j;
			}
		}
		swap_sorting(ptr[min_index], ptr[i]);
	}

	std::cout << std::endl << "Sorted array:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << ptr[i] << " ";
	}
}

//Selection Sort for singly linked list
void S_LinkedList::SLL_SelectionSort() {
	Node* ptr1 = head;
	Node* ptr2 = nullptr, * min = nullptr;
	while (ptr1) {
		min = ptr1;
		ptr2 = ptr1->GetNodeNext();
		while (ptr2) {
			if (min->GetNodeValue() > ptr2->GetNodeValue()) {
				swap_sorting(min, ptr2);
			}
			ptr2 = ptr2->GetNodeNext();
		}
		ptr1 = ptr1->GetNodeNext();
	}

	std::cout <<std::endl << "List after sorting:" << std::endl;
	Node* temp = head;
	while (temp) {
		std::cout << temp->GetNodeValue() << " ";
		temp = temp->GetNodeNext();
	}
}