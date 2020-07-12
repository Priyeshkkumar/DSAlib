#pragma once

#include"Node.h"

class BST {
	Node_Tree* root;

	//function to find inorder successor of a given node
	Node_Tree* BST_InorderSuccessor(Node_Tree* ptr);
	//internal function to search and retrun the node with given value
	Node_Tree* BST_SearchInternal(int element);
	//function to do inorder traversal of tree from given node
	void BST_Inorder(Node_Tree* root);
	//function to do preorder traversal of tree from given node
	void BST_Preorder(Node_Tree* root);
	//function to do postorder traversal of tree from given node
	void BST_Postorder(Node_Tree* root);

public:
	BST() {
		root = nullptr;
	}

	//function to insert an element in BST
	void BST_Insert(int element);
	//function to search an element in tree
	void BST_Search(int element);
	//function to delete a node from BST
	void BST_Delete(int element);
	//function to display elements of BST
	void Display_Inorder();
	//function to display elements of BST
	void Display_Postorder();
	//function to display elements of BST
	void Display_Preorder();

	void BST_DestructorHelper(Node_Tree* root) {
		while (root) {
			if (root->GetNodeLeft() == nullptr && root->GetNodeRight() == nullptr) {
				delete root;
			}
			else {
				BST_DestructorHelper(root->GetNodeLeft());
				BST_DestructorHelper(root->GetNodeRight());
			}
		}
	}
	~BST() {
		BST_DestructorHelper(root);
		std::cout << "Destructor BST";
	}
};