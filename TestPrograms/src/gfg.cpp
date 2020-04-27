#include<iostream>

void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

void min_heapify(int* arr, int& index, int& current_index) {
	int left_index = (2 * index) + 1;
	int right_index = (2 * index) + 2;
	int smallest_index = index;
	
	if (left_index < current_index && arr[left_index] < arr[smallest_index]) {
		smallest_index = left_index;
	}
	if (right_index < current_index && arr[right_index] < arr[smallest_index]) {
		smallest_index = right_index;
	}
	if (smallest_index != index) {
		swap(arr[smallest_index], arr[index]);
		min_heapify(arr, smallest_index, current_index);
	}
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n, current_index = 0, parent;
		std::cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; ++i) {
			int temp;
			if (i == 0) {
				std::cin >> temp;
				arr[0] = temp;
				current_index++;
			}
			else {
				current_index = i;
				std::cin >> temp;
				arr[current_index] = temp;
				parent = (current_index - 1) / 2;
				while (current_index >= 0 && arr[parent] > arr[current_index]) {
					swap(arr[parent], arr[current_index]);
					current_index = parent;
					parent = (parent - 1) / 2;
				}
				current_index++;
			}
		}
		int k;
		std::cin >> k;
		int smallest;
			for (int i = 0; i < k; ++i) {
			int first_index = 0;
			smallest = arr[first_index];
 			arr[first_index] = arr[n-1];
			n--;
			min_heapify(arr, first_index, n);
		}
		std::cout << smallest << std::endl;
	}
}