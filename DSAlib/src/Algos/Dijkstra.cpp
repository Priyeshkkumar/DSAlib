//Single source shortest path - Dijkstra's Algorithm, No negative weights are allowed in this algorithm
//Implemented using Min Heap
#include"Algos.h"
#include<climits>

void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

struct Graph_Node {
	int node_value;;
	int node_wt;
};

class D_Min_Heap {
	int heap_capacity;
	int heap_elements;
	struct Graph_Node* node_arr;
public:
	D_Min_Heap() = delete;
	D_Min_Heap(int capacity) {
		int heap_capacity = capacity;
		int heap_elements = 0;
		node_arr = new struct Graph_Node[heap_capacity];
	}
	//function that returns parent inde
	int D_MinH_parent_index(int index) {
		return (index - 1) / 2;
	}

	//function that returns left child index
	int D_MinH_left_child_index(int index) {
		return (2 * index) + 1;
	}

	//function that returns right child index
	int D_MinH_right_child_index(int index) {
		return (2 * index) + 2;
	}
	//function to insert a graph node
	void D_MinH_Insert(struct Graph_Node graph_nodes);

	//function to calculate min distance
	void D_CalculateDistance(DWGraph* graph);
};

void D_Min_Heap::D_MinH_Insert(struct Graph_Node graph_node) {
	if (heap_capacity == heap_elements) {
		std::cout << "Overflow, Heap Full!!";
		exit(0);
		}
	else {
		if (heap_elements == 0) {
			node_arr[0] = graph_node;
			heap_elements++;
		}
		else {
			int current_index = heap_elements;
			node_arr[heap_elements] = graph_node;
			heap_elements++;
			int parent_index = D_MinH_parent_index(heap_elements); 
			while (parent_index >= 0 && node_arr[parent_index].node_wt > node_arr[current_index].node_wt) {
				swap(node_arr[parent_index].node_wt, node_arr[current_index].node_wt);
				current_index = parent_index;
				parent_index = D_MinH_parent_index(parent_index);
			}
		}
	}
}

void D_Min_Heap::D_CalculateDistance(DWGraph* graph) {
	std::cout << "Node " << node_arr[0].node_value << " Cost to reach: " << node_arr[0].node_wt<<std::endl;
	int To_add = node_arr[0].node_wt;
	node_arr[0] = node_arr[heap_elements - 1];
	Weighted_Node* ptr = graph->DWG_GetNodeHead()[node_arr[0].node_value];
	while (ptr) {

	}
}

void Dijkstra(DWGraph* graph, int source) {
	int GVertex = graph->DWG_GetVertex();
	D_Min_Heap* min_heap = new D_Min_Heap(GVertex);
	struct Graph_Node* graph_nodes = new Graph_Node[GVertex];
	for (int i = 0; i < GVertex; ++i) {
		if (i == source) {
			graph_nodes[source].node_value = source;
			graph_nodes[source].node_wt = 0;
			min_heap->D_MinH_Insert(graph_nodes[i]);
		}
		graph_nodes[i].node_value = i;
		graph_nodes[i].node_wt = INT_MAX;
		min_heap->D_MinH_Insert(graph_nodes[i]);
	}
	
	min_heap->D_CalculateDistance(graph);
}