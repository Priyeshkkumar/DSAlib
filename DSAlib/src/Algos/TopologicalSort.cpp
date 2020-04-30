#include"Algos.h"

//use this algo when using stack with array
#ifdef STACK_USING_ARRAY

void TopologicalSort(DGraph* graph) {
	//Do topological sorting only if it is a Directed Acyclic Graph(DAG)
	if (!IsCycle(graph)) {
		int GVertex = graph->DG_GetVertex();
		bool* visited = new bool[GVertex];//stored on heap, therefore need to be deleted
		for (int i = 0; i < GVertex; ++i) {
			visited[i] = false;
		}
		Stack stack(GVertex);//Since stored on stack, therefore no need to call delete
		for (int i = 0; i < GVertex; ++i) {
			if (graph->DG_GetNodeHead()[i]) {
				if (visited[i] == true) {
					continue;
				}
				visited[i] = true;
				stack.Spush(i);
				Node* ptr = graph->DG_GetNodeHead()[stack.Stop()];
				while (ptr) {
					if (visited[ptr->GetNodeValue()] != true) {
						visited[ptr->GetNodeValue()] = true;
						stack.Spush(ptr->GetNodeValue());
					}
					ptr = ptr->GetNodeNext();
				}
			}
		}
		int stack_top = stack.Stop();
		std::cout << "\nTopological Sorting:\n";
		while (!stack.SisEmpty()) {
			std::cout << "<-" << stack.Spop();
		}
	}
	else{
		std::cout << "\nGraph is not DAG, therefore Topological sort not possible!!";
	}
}

#endif