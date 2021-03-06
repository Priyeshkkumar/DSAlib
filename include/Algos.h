//Header File for all Algorithm Definitions

#pragma once
#include"graph.h"
#include"BinarySearchTree.h"
#include"Queue.h"
#include"Stack.h"
#include"Heap.h"
#include"LinkedList.h"

//Graph Algorithms
void BFS(DGraph* graph, int start);
void DFS(DGraph* graph, int start);
bool IsCycle(DGraph* graph);
void TopologicalSort(DGraph* graph);
void StronglyConnected(DGraph* graph);
void Dijkstra(DWGraph* graph, int source);


//Sorting Algorithms

void SelectionSort(int* ptr, int size);

void BubbleSort(int* ptr, int size);
