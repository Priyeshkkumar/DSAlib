#include"Algos.h"

//use ths algo when using queue with array
#ifdef QUEUE_USING_ARRAY

void BFS(DGraph* graph, int start) {
	//array of boolean to mark visited nodes
	int* label;
	int GVertex = graph->DG_GetVertex();
	label = new int[GVertex];
	for (int i = 0; i < GVertex; ++i) {
		label[i] = 0;
	}

	//A queue to store nodes being visited
	Queue queue(GVertex);//Since stored on stack, therefore no need to call delete

	queue.Qenqueue(start);
	label[start] = 1;
	std::cout << "\n\nBFS\n";
	while (!queue.QisEmpty()) {
		int node_value = queue.Qdequeue();
		std::cout << "->" << node_value;
		Node* ptr = graph->DG_GetNodeHead()[node_value];
		while (ptr) {
			if (label[ptr->GetNodeValue()] == 0) {
				label[ptr->GetNodeValue()] = 1;
				queue.Qenqueue(ptr->GetNodeValue());
			}
			ptr = ptr->GetNodeNext();
		}
	}
}

#endif