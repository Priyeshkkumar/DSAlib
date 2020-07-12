#include"Algos.h"

int main() {
	/*int size;
	std::cout << std::endl << "Enter Size of array:";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << std::endl << "Enter " << size << " elements" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	BubbleSort(arr, size);*/

	S_LinkedList* head = new S_LinkedList;

	head->SLL_add_back(64);
	head->SLL_add_back(25);
	head->SLL_add_back(12);
	head->SLL_add_back(22);
	head->SLL_add_back(11);
	head->Display();

	head->SLL_BubbleSort();

	delete head;
	//delete[] arr;
}