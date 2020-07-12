#include"Algos.h"
#include"SwapFunctions.h"

void BubbleSort(int* arr, int size) {
	for (int i = 0; i <  size; ++i) {
		for (int j = 0; j < size - (i+1); ++j) {
			if (arr[j] > arr[j + 1]) {
				swap_sorting(arr[j], arr[j + 1]);
			}
		}
	}

	std::cout << std::endl << "After Bubble Sorting:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}

void S_LinkedList::SLL_BubbleSort() {
	Node* ptr = head;
	int size = 1;
	while (ptr->GetNodeNext()) {
		ptr = ptr->GetNodeNext();
		++size;
	}
	int m = 1;
	while (m != size) {
		ptr = head;
		int n = size - m;
		while (n--) {
			if (ptr->GetNodeValue() > ptr->GetNodeNext()->GetNodeValue()) {
				swap_sorting(ptr, ptr->GetNodeNext());
			}
			ptr = ptr->GetNodeNext();
		}
		m++;
	}

	std::cout << std::endl << "List after Bubble sorting:" << std::endl;
	Node* temp = head;
	while (temp) {
		std::cout << temp->GetNodeValue() << " ";
		temp = temp->GetNodeNext();
	}
}