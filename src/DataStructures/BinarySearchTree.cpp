#include "BinarySearchTree.h"

void BST::BST_Insert(int element) {
	Node_Tree* temp = new Node_Tree;
	temp->SetNodeRight(nullptr);
	temp->SetNodeLeft(nullptr);
	temp->SetNodeValue(element);
	if (root == NULL) {
		root = temp;
	}
	else {
		Node_Tree* ptr = root;
		while (ptr) {
			if (element < ptr->GetNodeValue()) {
				if (ptr->GetNodeLeft() == nullptr) {
					ptr->SetNodeLeft(temp);
					break;
				}
				else {
					ptr = ptr->GetNodeLeft();
				}
			}
			else {
				if (ptr->GetNodeRight() == nullptr) {
					ptr->SetNodeRight(temp);
					break;
				}
				else {
					ptr = ptr->GetNodeRight();
				}
			}
		}
	}
}


void BST::BST_Search(int element) {
	Node_Tree* temp = nullptr;
	temp = BST_SearchInternal(element);
	if (temp != nullptr) {
		std::cout << std::endl << element << " Found!!";
	}
	else {
		std::cout << std::endl << element << " Not Found!!";
	}
}
Node_Tree* BST::BST_SearchInternal(int element) {
	//if element matches with element
	if (root->GetNodeValue() == element) {
		return root;
	}//else traverse the tree 
	else {
		Node_Tree* ptr = root;
		Node_Tree* parent = nullptr;
		while (ptr) {
			if (element == ptr->GetNodeValue()) {
				return parent;
			}
			else if (element < ptr->GetNodeValue()) {
				parent = ptr;
				ptr = ptr->GetNodeLeft();
			}
			else if (element > ptr->GetNodeValue()) {
				parent = ptr;
				ptr = ptr->GetNodeRight();
			}
		}
		if (ptr == nullptr) {
			return nullptr;
		}
	}
}

Node_Tree* BST::BST_InorderSuccessor(Node_Tree* ptr) {
	while (ptr->GetNodeLeft() != nullptr) {
		ptr = ptr->GetNodeLeft();
	}
	return ptr;
}


void BST::BST_Delete(int element) {
	
	//if root is null
	if (root == nullptr) {
		std::cout << std::endl << "Tree is Empty!!";
		return;
	}

	if (root->GetNodeValue() == element) {
		std::cout << std::endl << "Deleting " << element;
		//if only root
		if (root->GetNodeLeft() == nullptr && root->GetNodeRight() == nullptr) {
			delete root;
			root = nullptr;
			return;
		}
		//if root with onr child
		if (root->GetNodeLeft() == nullptr) {
			Node_Tree* temp = root;
			root = root->GetNodeRight();
			delete temp;
			return;
		}
		else if (root->GetNodeRight() == nullptr) {
			Node_Tree* temp = root;
			root = root->GetNodeLeft();
			delete temp;
			return;
		}
		else {
			Node_Tree* successor;
			//search for inorder successor, so that it's value could be exchanged with that of ptr
			successor = BST_InorderSuccessor(root->GetNodeRight());
			int value_to_change = successor->GetNodeValue();
			BST_Delete(value_to_change);
			root->SetNodeValue(value_to_change);
		}
	}
	else {
		//search for the node, if node is found parent will store element's parent node
		Node_Tree* parent = BST_SearchInternal(element);
		if (parent == nullptr) {
			std::cout << std::endl << element << " Not Found!!";
			return;
		}
		else {
			std::cout << std::endl << "Deleting " << element;
		}


		Node_Tree* ptr = nullptr;

		//set appropriate value of child of parent
		if (parent->GetNodeLeft() && parent->GetNodeLeft()->GetNodeValue() == element) {
			ptr = parent->GetNodeLeft();
		}
		else if (parent->GetNodeRight() && parent->GetNodeRight()->GetNodeValue() == element) {
			ptr = parent->GetNodeRight();
		}

		//Case 1 - When no childern
		if (parent->GetNodeLeft() && parent->GetNodeLeft()->GetNodeValue() == element && ptr->GetNodeLeft() == nullptr && ptr->GetNodeRight() == nullptr) {
			parent->SetNodeLeft(nullptr);
			delete ptr;
			return;
		}
		else if (parent->GetNodeRight() && parent->GetNodeRight()->GetNodeValue() == element && ptr->GetNodeLeft() == nullptr && ptr->GetNodeRight() == nullptr) {
			parent->SetNodeRight(nullptr);
			delete ptr;
			return;
		}


		//Case 2- when there is only one child to ptr
		if (ptr->GetNodeLeft() == nullptr) {
			parent->SetNodeLeft(ptr->GetNodeRight());
			delete ptr;
			return;
		}
		else if (ptr->GetNodeRight() == nullptr) {
			parent->SetNodeRight(ptr->GetNodeLeft());
			delete ptr;
			return;
		}//case 3 - when there are two children of ptr
		else {
			Node_Tree* successor;
			//search for inorder successor, so that it's value could be exchanged with that of ptr
			successor = BST_InorderSuccessor(ptr->GetNodeRight());
			int value_to_change = successor->GetNodeValue();
			BST_Delete(value_to_change);
			ptr->SetNodeValue(value_to_change);
		}
	}
}
//it can also be implemented using stack
void BST::BST_Inorder(Node_Tree* root) {
	if (root == nullptr)
		return;

		BST_Inorder(root->GetNodeLeft());
		std::cout << root->GetNodeValue() << " ";
		BST_Inorder(root->GetNodeRight());
}

void BST::BST_Postorder(Node_Tree* root) {
	if (root != nullptr) {
		BST_Postorder(root->GetNodeLeft());
		BST_Postorder(root->GetNodeRight());
		std::cout << root->GetNodeValue() << " ";
	}
}

void BST::BST_Preorder(Node_Tree* root) {
	if (root != nullptr) {
		std::cout << root->GetNodeValue() << " ";
		BST_Preorder(root->GetNodeLeft());
		BST_Preorder(root->GetNodeRight());
	}
}

void BST::Display_Inorder() {
	std::cout << std::endl << "Inorder Traversal of BST is:" << std::endl;
	BST_Inorder(root);
}
void BST::Display_Postorder() {
	std::cout << std::endl << "Postorder Traversal of BST is:" << std::endl;
	BST_Postorder(root);
}
void BST::Display_Preorder() {
	std::cout << std::endl << "Preorder Traversal of BST is:" << std::endl;
	BST_Preorder(root);
}





