#include"Algos.h"
#include<climits>

struct Heap_Node {
	int HN_Vertex;
	int HN_wt;
};

//function to swap two Heap_Node types
void Swap(struct Heap_Node& first, struct Heap_Node& second) {
	int temp = first.HN_Vertex;
	first.HN_Vertex = second.HN_Vertex;
	second.HN_Vertex = temp;

	temp = first.HN_wt;
	first.HN_wt = second.HN_wt;
	second.HN_wt = temp;
}

class D_Min_Heap {
	int MH_capacity, MH_elements;
	struct Heap_Node* MH_arr;
public:
	D_Min_Heap() = delete;
	D_Min_Heap(int capacity) {
		MH_capacity = capacity;
		MH_elements = 0;
		MH_arr = new struct Heap_Node[MH_capacity];
	}
	//function to return D_Min_Heap elements
	int MH_get_MH_elements() {
		return MH_elements;
	}
	//function to return pointer to MH_arr
	struct Heap_Node* MH_get_MH_arr() {
		return MH_arr;
	}
	//function that returns parent index
	int MH_get_parent(int index) {
		return (index - 1) / 2;
	}
	//function that returns left_child_index
	int MH_get_left(int index) {
		return (2*index) + 1;
	}
	//function that returns right_child_index
	int MH_get_right(int index) {
		return (2 * index) + 2;
	}

	//function to insert a Heap_Node in D_Min_Heap
	void MH_Insert(struct Heap_Node element);
	//function to min heapify Heap_Node type Heap
	void MH_Heapify(int index);
	//function to extract min Heap_Node
	struct Heap_Node MH_ExtractMin();

	~D_Min_Heap() {
		delete[] MH_arr;
	}
};

void D_Min_Heap::MH_Insert(struct Heap_Node element) {
	if (MH_elements == MH_capacity) {
		std::cout << "Overfolw, Heap Full!";
		exit(0);
	}
	if (MH_elements == 0) {
		MH_arr[0] = element;
		MH_elements++;
	}
	else {
		int current_index = MH_elements;
		int parent_index = MH_get_parent(current_index);
		MH_arr[current_index] = element;
		MH_elements++;
		//traverse up the heap until parent's weight is greater
		while (MH_arr[current_index].HN_wt < MH_arr[parent_index].HN_wt) {
			Swap(MH_arr[current_index], MH_arr[parent_index]);
			current_index = parent_index;
			parent_index = MH_get_parent(current_index);
		}
 	}
}

struct Heap_Node D_Min_Heap::MH_ExtractMin() {
	if (MH_elements <= 0) {
		std::cout << "Undeflow, Heap Empty!!";
		exit(0);
	}
	else if (MH_elements == 1) {
		MH_elements--;
		return MH_arr[0];
	}
	else {
		struct Heap_Node temp = MH_arr[0];
		MH_arr[0] = MH_arr[MH_elements - 1];
		MH_Heapify(0);
		return temp;
	}
}

void D_Min_Heap::MH_Heapify(int index) {
	int left_child_index = MH_get_left(index);
	int right_child_index = MH_get_right(index);
	int smallest = index;

	if (left_child_index <= MH_elements && MH_arr[left_child_index].HN_wt < MH_arr[smallest].HN_wt) {
		smallest = left_child_index;
	}
	if (right_child_index <= MH_elements && MH_arr[right_child_index].HN_wt < MH_arr[smallest].HN_wt) {
		smallest = right_child_index;
	}
	if (smallest != index) {
		Swap(MH_arr[index], MH_arr[smallest]);
		MH_Heapify(smallest);
	}
}

void Dijkstra(DWGraph* graph, int source) {
	int GVertex = graph->DWG_GetVertex();
	//make a D_Min_Heap of GVertex nodes
	D_Min_Heap* min_heap = new D_Min_Heap(GVertex);
	//a struct Heap_Node type variable
	struct Heap_Node temp;
	for (int i = 0; i < GVertex; ++i) {
		if (i == source) {
			temp.HN_Vertex = source;
			temp.HN_wt = 0;
		}
		else {
			temp.HN_Vertex = i;
			temp.HN_wt = INT_MAX;
		}
		min_heap->MH_Insert(temp);
	}
	while (min_heap->MH_get_MH_elements()-1 >= 0) {
		
		temp = min_heap->MH_ExtractMin();

		std::cout << "Node: " << temp.HN_Vertex << " Cost To Reach: " << temp.HN_wt << std::endl;

		int to_traverse = temp.HN_Vertex;
		//traverse the adjacency list of extracted node and update it's weight in heap
		Weighted_Node* ptr = graph->DWG_GetNodeHead()[to_traverse];
		while (ptr) {
			int new_wt = temp.HN_wt + ptr->GetNodeWeight();
			int current_wt = min_heap->MH_get_MH_arr()[ptr->GetNodeValue()].HN_wt;
			//There is a problem here the algo is updating the weight at the 4th index instead to updating it
			//where the fourth node is...
			if (current_wt > new_wt) {
				min_heap->MH_get_MH_arr()[ptr->GetNodeValue()].HN_wt = new_wt;
				int current_index = ptr->GetNodeValue();
				int parent_index = min_heap->MH_get_parent(ptr->GetNodeValue());
				while (min_heap->MH_get_MH_arr()[current_index].HN_wt < min_heap->MH_get_MH_arr()[parent_index].HN_wt) {
					Swap(min_heap->MH_get_MH_arr()[current_index], min_heap->MH_get_MH_arr()[parent_index]);
					current_index = parent_index;
					parent_index = min_heap->MH_get_parent(current_index);
				}
			}
			ptr = ptr->GetNodeNext();
		}
	}
}
