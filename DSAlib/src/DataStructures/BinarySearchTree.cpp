#include "BinarySearchTree.h"

//This class is using Node_Two, therefore node->next is equivalent to node->right_child
//and node->prev is equivalent to node->left_child...

void BST::BST_Insert(int element) {
	Node_Two* temp = new Node_Two;
	temp->SetNodeNext(nullptr);//next means right child
	temp->SetNodePrev(nullptr);//prev means left child
	temp->SetNodeValue(element);
	if (root == NULL) {
		root = temp;
	}
	else {
		Node_Two* ptr = root;
		while (ptr) {
			if (element >= ptr->GetNodeValue()) {
				ptr = ptr->GetNodeNext();
			}
			else {
				ptr = ptr->GetNodePrev();
			}
		}
		ptr = temp;
	}
}

//it can also be implemented using stack
void BST::BST_Inorder(Node_Two* node) {
	if (node != nullptr) {
		BST_Inorder(node->GetNodePrev());
		std::cout << node->GetNodeValue() << " ";
		BST_Inorder(node->GetNodeNext());
	}
}

