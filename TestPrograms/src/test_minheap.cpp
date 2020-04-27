#include"Heap.h"

int main() {
	Min_Heap* heap = new Min_Heap(10);
	heap->MinH_Insert(12);
	heap->MinH_Insert(8);
	heap->MinH_Insert(10);
	heap->MinH_Insert(3);
	heap->MinH_Insert(1);
	heap->MinH_Insert(2);
	heap->MinH_Insert(15);
	heap->MinH_Insert(5);
	heap->MinH_Insert(4);
	heap->MinH_Insert(45);

	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();


	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	heap->MinH_ExtractMin();
	heap->Display();

	delete heap;
}