//Kosaraju's Algorithm

#include"Algos.h"

Queue* SCC_DFS_One(DGraph* graph) {
	int GVertex = graph->DG_GetVertex();
	//array of boolean to store visited nodes
	bool* visited = new bool[GVertex];//needs to be deleted
	//array to store result of DFS
	Queue* SCC_queue = new Queue(GVertex);
	int incrementer = 0;
	for (int i = 0; i < GVertex; ++i) {
		visited[i] = false;
	}
	for (int i = 0; i < GVertex; ++i) {
		if (graph->DG_GetNodeHead()[i]) {
			if (visited[i] == true) {
				continue;
			}
			visited[i] = true;
			SCC_queue->Qenqueue(i);
			Node* ptr = graph->DG_GetNodeHead()[i];
			while (ptr) {
				if (visited[ptr->GetNodeValue()] != true) {
					SCC_queue->Qenqueue(ptr->GetNodeValue());
					visited[ptr->GetNodeValue()] = true;
				}
				ptr = ptr->GetNodeNext();
			}
		}
		else {
			visited[i] = true;
			SCC_queue->Qenqueue(i);
		}
	}
	return SCC_queue;
}

void SCC_DFS_Two(DGraph* reverse_graph, Queue* queue) {

	int GVertex = reverse_graph->DG_GetVertex();
	bool* visited = new bool[GVertex];
	for (int i = 0; i < GVertex; ++i) {
		visited[i] = false;
	}

	Stack* stack = new Stack(GVertex);

	std::cout << "\nStrongly Connected Components:\n";
	while (!queue->QisEmpty()) {
		int current_node_queue = queue->Qdequeue();
		if (reverse_graph->DG_GetNodeHead()[current_node_queue]) {
			if (visited[current_node_queue] == false) {
				
				stack->Spush(current_node_queue);
				std::cout << "->" << current_node_queue;
				visited[current_node_queue] = true;

				while (!stack->SisEmpty()) {
 					int current_node_stack = stack->Spop();
					Node* ptr = reverse_graph->DG_GetNodeHead()[current_node_stack];
					while (ptr) {
						if (visited[ptr->GetNodeValue()] == false) {
							visited[ptr->GetNodeValue()] = true;
							std::cout << "->" << ptr->GetNodeValue();
							stack->Spush(ptr->GetNodeValue());
						}
						ptr = ptr->GetNodeNext();
					}
				}
				std::cout << std::endl;
			}
		}
		else {
			std::cout <<"->" << current_node_queue << std::endl;
			visited[current_node_queue] = true;
		}
	}
}

void SCC_Add_ReverseEdge(DGraph* reverse_graph, int u, int v) {
	if (reverse_graph->DG_GetNodeHead()[u] == nullptr) {
		Node* temp = new Node;
		temp->SetNodeValue(v);
		temp->SetNodeNext(nullptr);
		reverse_graph->DG_GetNodeHead()[u] = temp;
	}
	else {
		Node* temp = new Node;
		temp->SetNodeValue(v);
		temp->SetNodeNext(reverse_graph->DG_GetNodeHead()[u]->GetNodeNext());
		reverse_graph->DG_SetHead(temp, u);
	}
}

DGraph* SCC_ReverseEdges(DGraph* graph) {
	int GVertex = graph->DG_GetVertex();
	DGraph* reverse_graph = new DGraph(GVertex);
	for (int i = 0; i < GVertex; ++i) {
		if (graph->DG_GetNodeHead()[i]) {
			Node* ptr = graph->DG_GetNodeHead()[i];
			while (ptr) {
				SCC_Add_ReverseEdge(reverse_graph, ptr->GetNodeValue(), i); 
				ptr = ptr->GetNodeNext();
			}
		}
	}
	return reverse_graph;
}

void Display(DGraph* reverse_graph) {
	std::cout << "\n####################################\n";
	std::cout << "\nReverse Graph:";
	for (int i = 0; i < reverse_graph->DG_GetVertex(); ++i) {
		std::cout << "\nVertex " << i << "\t";
		Node* ptr = reverse_graph->DG_GetNodeHead()[i];
		while (ptr) {
			std::cout << "->" << ptr->GetNodeValue();
			ptr = ptr->GetNodeNext();
		}
	}
	std::cout << "\n\n####################################\n";
}

void StronglyConnected(DGraph* graph) {
	//Customized DFS that outputs a array;
	Queue* SCC_queue = SCC_DFS_One(graph);
	DGraph* reverse_graph = SCC_ReverseEdges(graph);
	Display(reverse_graph);
	SCC_DFS_Two(reverse_graph, SCC_queue);
	delete reverse_graph;
}