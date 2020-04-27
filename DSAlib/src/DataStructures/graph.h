#pragma once
#include<iostream>
#include"Node.h"

class DGraph {
	int DG_Vertex;
	Node** DG_Head;
public:
	DGraph() = delete;
	DGraph(int vertex) {
		std::cout << "\nInside DGraph";
		DG_Vertex = vertex;
		DG_Head = new Node* [DG_Vertex];//array of Nodes
		//initializing head poiners of all Vertex list to zero
		for (int i = 0; i < DG_Vertex; ++i) {
			DG_Head[i] = nullptr;
		}
	}
	int DG_GetVertex() {
		return DG_Vertex;
	}
	Node** DG_GetNodeHead() {
		return DG_Head;
	}
	void DG_SetHead(Node* ptr, int vertex) {
		DG_Head[vertex]->SetNodeNext(ptr);
	}

	//function to add new edge to graph
	virtual void AddNewEdge(int u, int v);
	void Display();

	~DGraph() {
		std::cout << "\nDestructor Graph!";
		if (DG_Head != NULL) {
			for (int i = 0; i < DG_Vertex; ++i) {
				if (DG_Head + i != nullptr) {
					Node* ptr = *(DG_Head + i);
					while (ptr != NULL) {
						Node* temp = ptr;
						ptr = ptr->GetNodeNext();
						delete temp;
					}
				}
			}
			delete[] DG_Head;
		}
	}
};

//A class for Undirected graph
class UGraph : public DGraph {
public:
	UGraph(int vertex)
		//Making a Graph object and initializing the constructor with vertex
		//here we have to provide arguments to constructor, therefore we need to explicitly call the constructor
		:DGraph( vertex ) {
		std::cout << "\nInside UGraph";
	}
	//extending functionality of add new edge function inherited from DGraph class
	void AddNewEdge(int u, int v) override;
};

//Customized Weighted_Node class to add weights to each node for Weighted graphs
class Weighted_Node {
	int value;
	int weight;
	Weighted_Node* next;
public:
	Weighted_Node() {
		value = 0;
		weight = 0;
		next = nullptr;
	}
	int GetNodeValue() {
		return value;
	}
	Weighted_Node* GetNodeNext() {
		return next;
	}
	void SetNodeValue(int vertex) {
		value = vertex;
	}
	void SetNodeNext(Weighted_Node* ptr) {
		next = ptr;
	}
	int GetNodeWeight() {
		return weight;
	}
	void SetNodeWeight(int value) {
		weight = value;
	}
};

//A class for Directed Weighted Graph
class DWGraph {
	int DWG_Vertex;
	Weighted_Node** DWG_Head;
public:
	//Do not allow default constructor
	DWGraph() = delete;

	DWGraph(int vertex) {
		std::cout << "\nInside Weighted Graph Constructor\n\n";
		DWG_Vertex = vertex;
		DWG_Head = new Weighted_Node* [DWG_Vertex];
		for (int i = 0; i < DWG_Vertex; ++i) {
			DWG_Head[i] = nullptr;
		}
	}

	int DWG_GetVertex() {
		return DWG_Vertex;
	}
	Weighted_Node** DWG_GetNodeHead() {
		return DWG_Head;
	}
	void DWG_SetHead(Weighted_Node* ptr, int vertex) {
		DWG_Head[vertex]->SetNodeNext(ptr);
	}

	//function to add new edge to graph
	void AddNewEdge(int u, int v, int weight);
	void Display();

	~DWGraph() {
		std::cout << "\nDestructor Graph!";
		if (DWG_Head != NULL) {
			for (int i = 0; i < DWG_Vertex; ++i) {
				if (DWG_Head + i != nullptr) {
					Weighted_Node* ptr = *(DWG_Head + i);
					while (ptr != NULL) {
						Weighted_Node* temp = ptr;
						ptr = ptr->GetNodeNext();
						delete temp;
					}
				}
			}
			delete[] DWG_Head;
		}
	}

};

