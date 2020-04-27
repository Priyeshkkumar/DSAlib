//Function to detect a cycle in a graph using DFS and Colors Symbolization
#include"Algos.h"

//Enum to mark the color the of node
enum class Color {
	White,
	Gray,
	Black
};

//Struct for node property
struct DG_Node_Property {
	bool visited;
	Color color;
};

bool IsCycle(DGraph* graph) {
	int GVertex = graph->DG_GetVertex();
	struct DG_Node_Property* node_property = new DG_Node_Property[GVertex];

	for (int i = 0; i < GVertex; ++i) {
		node_property[i].visited = false;
		node_property[i].color = Color::White;
	}

	//Stack to keep node explored
	Stack* stack = new Stack(GVertex);//Since stored on heap, therefore need to call delete

	//start traversing all nodes from first node
	for (int i = 0; i < GVertex; ++i) {
		//check whether there exists an adjacency list of current node, i.e outgoing nodes
		if (graph->DG_GetNodeHead()[i]) {

			//if node is already visited, continue
			if (node_property[i].visited == true && node_property[i].color == Color::Gray) {
				node_property[i].color = Color::Black;
				continue;
			}
			//push node in stack
			stack->Spush(i);

			//now traverse the adjacency list of node being explored
			//DFS like function...
			while (!stack->SisEmpty()) {
				int current_node = stack->Spop();
				node_property[current_node].visited = true;
				Node* ptr = graph->DG_GetNodeHead()[current_node];
				if (ptr) {
					node_property[current_node].color = Color::Gray;
					while (ptr) {
						//if node next to current node is already visited and gray then return
						//that there is a cycle
						if (node_property[ptr->GetNodeValue()].color == Color::Gray) {
							delete stack;
							return true;
						}
						else if (node_property[ptr->GetNodeValue()].color == Color::White) {
							stack->Spush(ptr->GetNodeValue());
						}
						ptr = ptr->GetNodeNext();
					}
				}
			}
		}
		node_property[i].color = Color::Black;
	}
	delete stack;
	return false;
}