#include"BinarySearchTree.h"

int main() {
	BST* root = new BST;

	//root->BST_Insert(10);
	//root->BST_Insert(6);
	//root->BST_Insert(16);
	//root->BST_Insert(3);
	//root->BST_Insert(8);
	//root->BST_Insert(13);
	//root->BST_Insert(19);
	//root->BST_Insert(2);
	//root->BST_Insert(20);
	//root->BST_Insert(4);
	//root->BST_Insert(5);
	//root->BST_Insert(9);

	/*root->BST_Insert(10);
	root->BST_Insert(1);
	root->BST_Insert(3);
	root->BST_Insert(4);
	root->BST_Insert(5);
	root->BST_Insert(2);
	root->BST_Insert(15);
	root->BST_Insert(17);
	root->BST_Insert(16);
	root->BST_Insert(18);*/

	root->BST_Insert(10);
	root->BST_Insert(1);
	root->BST_Insert(15);
	root->BST_Insert(13);
	root->BST_Insert(20);
	root->BST_Insert(18);
	root->BST_Insert(16);
	root->BST_Insert(19);
	root->BST_Insert(23);
	root->BST_Insert(22);
	root->BST_Insert(24);

	root->Display_Inorder();
	/*root->Display_Postorder();
	root->Display_Preorder();*/

	/*root->BST_Search(6);
	root->BST_Search(1);*/

	std::cout << std::endl << "Deletion Begins!!" << std::endl;
	root->BST_Delete(20);
	root->Display_Inorder();

	root->BST_Delete(1);
	root->Display_Inorder();

	root->BST_Delete(10);
	root->Display_Inorder();

	root->BST_Delete(15);
	root->Display_Inorder();

	root->BST_Delete(13);
	root->Display_Inorder();

	root->BST_Delete(18);
	root->Display_Inorder();

	root->BST_Delete(19);
	root->Display_Inorder();

	root->BST_Delete(16);
	root->Display_Inorder();

	root->BST_Delete(19);
	root->Display_Inorder();

	root->BST_Delete(22);
	root->Display_Inorder();

	root->BST_Delete(24);
	root->Display_Inorder();

	root->BST_Delete(23);
	root->Display_Inorder();

	root->BST_Delete(15);
	root->Display_Inorder();


	/*root->BST_Delete(15);
	root->Display_Inorder();*/

	//delete root;
}