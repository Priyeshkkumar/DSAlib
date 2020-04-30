#include"LinkedList.h"

int main() {
	S_LinkedList* head = new S_LinkedList;
	head->SLL_add_back(1);
	head->SLL_add_back(2);
	head->SLL_add_back(3);
	head->SLL_add_back(4);

	//head->LL_delete_back();
	//head->LL_delete_back();
	//head->LL_delete_back();
	//head->LL_delete_back();

	head->SLL_delete_position(5);
	/*head->SLL_delete_position(3);
	head->SLL_delete_position(2);
	head->SLL_delete_position(1);*/

	head->SLL_delete_element(5);
	head->Display();
	head->SLL_delete_element(4);
	head->Display();
	head->SLL_delete_element(3);
	head->Display();
	head->SLL_delete_element(2);
	head->Display();
	head->SLL_delete_element(1);
	head->Display();

	delete head;
}