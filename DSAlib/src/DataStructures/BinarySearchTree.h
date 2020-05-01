#pragma once

#include"Node.h"

class BST {
	Node_Two* root;
public:
	BST() {
		root = nullptr;
	}

	//function to insert an element in BST
	void BST_Insert(int element);
	//function to do inorder traversal of tree from given node
	void BST_Inorder(Node_Two* node);
	//function to search and retrun the node with given value
	void BST_Search(int element);
	//function to delete a node from BST
	void BST_Delete(int element);

	~BST() {

	}
};