#include"graph.h"

void DGraph::AddNewEdge( int u, int v) {
	if (DG_GetNodeHead()[u] == nullptr) {
		Node* temp = new Node;
		temp->SetNodeValue(v);
		temp->SetNodeNext(nullptr);
		DG_GetNodeHead()[u] = temp;
	}
	else {
		Node* temp = new Node;
		temp->SetNodeValue(v);
		temp->SetNodeNext(DG_GetNodeHead()[u]->GetNodeNext());
		DG_SetHead(temp, u);
	}
}

//extending functionality for Ugraph class
void UGraph::AddNewEdge(int u, int v) {

	if (DG_GetNodeHead()[u] == nullptr) {
		Node* temp = new Node;
		temp->SetNodeValue(v);
		temp->SetNodeNext(nullptr);
		DG_GetNodeHead()[u] = temp;
	}
	else {
		Node* temp = new Node;
		temp->SetNodeValue(v);
		temp->SetNodeNext(DG_GetNodeHead()[u]->GetNodeNext());
		DG_SetHead(temp, u);
	}
	//since undirected graph
	if (DG_GetNodeHead()[v] == nullptr) {
		Node* temp = new Node;
		temp->SetNodeValue(u);
		temp->SetNodeNext(nullptr);
		DG_GetNodeHead()[v] = temp;
	}
	else {
		Node* temp = new Node;
		temp->SetNodeValue(u);
		temp->SetNodeNext(DG_GetNodeHead()[v]->GetNodeNext());
		DG_SetHead(temp, v);
	}
}


void DGraph::Display() {
	std::cout << "\n####################################\n";
	std::cout << "\nGraph:";
	for (int i = 0; i < DG_GetVertex(); ++i) {
		std::cout << "\nVertex " << i << "\t";
		Node* ptr = DG_GetNodeHead()[i];
		while (ptr) {
			std::cout << "->" << ptr->GetNodeValue();
			ptr = ptr->GetNodeNext();
		}
	}
	std::cout << "\n\n####################################\n";
}


void DWGraph::AddNewEdge(int u, int v, int weight) {
	if (DWG_GetNodeHead()[u] == nullptr) {
		Weighted_Node* temp = new Weighted_Node;
		temp->SetNodeValue(v);
		temp->SetNodeWeight(weight);
		temp->SetNodeNext(nullptr);
		DWG_GetNodeHead()[u] = temp;;
	}
	else {
		Weighted_Node* temp = new Weighted_Node;
		temp->SetNodeValue(v);
		temp->SetNodeWeight(weight);
		temp->SetNodeNext(DWG_GetNodeHead()[u]->GetNodeNext());
		DWG_SetHead(temp, u);
	}
}

void DWGraph::Display() {
	std::cout << "\n####################################\n";
	std::cout << "\nGraph:";
	for (int i = 0; i < DWG_GetVertex(); ++i) {
		std::cout << "\nVertex " << i << "\t";
		Weighted_Node* ptr = DWG_GetNodeHead()[i];
		while (ptr) {
			std::cout << "  -(" << ptr->GetNodeWeight() << ")-->" << ptr->GetNodeValue();
			ptr = ptr->GetNodeNext();
		}
	}
	std::cout << "\n\n####################################\n";
}