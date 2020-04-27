#include"Algos.h"

void DFS(DGraph* graph, int start) {
	int* label;
	int Gvertex = graph->DG_GetVertex();
	label = new int[Gvertex];
	for (int i = 0; i < Gvertex; ++i) {
		label[i] = 0;
	}

	Stack stack(Gvertex);//Since stored on stack, therefore no need to call delete
	stack.Spush(start);
	label[start] = 1;

	std::cout << "\nDFS:\n";
	while (!stack.SisEmpty()) {
		int node_value = stack.Spop();
		std::cout << "->" << node_value;
		Node* ptr = graph->DG_GetNodeHead()[node_value];
		while (ptr) {
			if (label[ptr->GetNodeValue()] == 0) {
				label[ptr->GetNodeValue()] = 1;
				stack.Spush(ptr->GetNodeValue());
			}
			ptr = ptr->GetNodeNext();
		}
	}
}