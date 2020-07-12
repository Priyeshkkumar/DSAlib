#include"Heap.h"

int main() {
	Max_Heap* heap = new Max_Heap(10);
	heap->MaxH_Insert(12);
	heap->MaxH_Insert(8);
	heap->MaxH_Insert(10);
	heap->MaxH_Insert(3);
	heap->MaxH_Insert(1);
	heap->MaxH_Insert(12);
	heap->MaxH_Insert(15);
	heap->MaxH_Insert(5);
	heap->MaxH_Insert(4);
	heap->MaxH_Insert(45);

	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	heap->MaxH_ExtractMax();
	heap->Display();

	delete heap;
}