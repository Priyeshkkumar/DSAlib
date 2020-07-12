#include<iostream>

int main() {
	int*** ptr_ptr_ptr;
	ptr_ptr_ptr = new int** [3];
	for (int i = 0; i < 3; ++i) {
		ptr_ptr_ptr[i] = new int* [3];
		for (int j = 0; j < 3; ++j) {
			ptr_ptr_ptr[i][j] = new int[3];
			for (int k = 0; k < 3; ++k) {
				ptr_ptr_ptr[i][j][k] = i+j+k;
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		std::cout<< i+1 << "th 2D matrix:\n";
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {

				std::cout << ptr_ptr_ptr[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	delete[] ptr_ptr_ptr;
}