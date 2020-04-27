//#pragma once
//#include"Node.h"
//
//
////here we are inheriting Node_With_Prev class in which next node is assumed as right child
////and prev node is assumed as left child...
//class BinaryTree :public Node_With_Prev{
//	//A private member to to store root of tree...
//	Node* root;
//	//A pointer that points to the last leaf node...
//	Node* current_leaf;
//public:
//	//BinaryTree constructor, no need to explicitly call 
//	//constructor of Node_With_Prev class, since it automatically calls it's constructor 
//	BinaryTree() {
//		root = nullptr;
//		current_leaf = nullptr;
//	}
//
//	void AddNewElement(int value) {
//		if (root == nullptr) {
//			Node_With_Prev* temp = new Node_With_Prev;
//			temp->SetNodeValue(value);
//			temp->SetNodeNext(nullptr);
//			temp->SetNodePrev(current_leaf);
//			root = temp;
//		}
//		else if()
//	}
//
//};