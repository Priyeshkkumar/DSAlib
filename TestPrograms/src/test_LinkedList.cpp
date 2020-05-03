#include"LinkedList.h"



int main() {
	D_LinkedList* head = new D_LinkedList;
	/*head->SLL_add_back(1);
	head->SLL_add_back(2);
	head->SLL_add_back(3);
	head->SLL_add_back(4);*/

	/*head->DLL_add_front(1);
	head->DLL_add_front(2);
	head->DLL_add_front(3);
	head->DLL_add_front(4);
	head->DLL_add_front(5);

	head->Display();

	std::cout << "\nDeleteing\n";
	head->DLL_delete_back();
	head->Display();
	head->DLL_delete_back();
	head->Display();
	head->DLL_delete_back();
	head->Display();
	head->DLL_delete_back();
	head->Display();
	head->DLL_delete_back();
	head->Display();*/


	head->DLL_add_back(1);
	head->DLL_add_back(2);
	head->DLL_add_back(3);
	head->DLL_add_back(4);
	head->DLL_add_back(5);

	head->Display();

	std::cout << "\n\nDeleteing\n";
	/*head->DLL_delete_front();
	head->Display();
	head->DLL_delete_front();
	head->Display();
	head->DLL_delete_front();
	head->Display();
	head->DLL_delete_front();
	head->Display();
	head->DLL_delete_front();
	head->Display();*/

	head->DLL_delete_position(1);
	head->Display();
	head->DLL_delete_position(3);
	head->Display();
	head->DLL_delete_position(3);
	head->Display();
	head->DLL_delete_position(2);
	head->Display();
	head->DLL_delete_position(1);
	head->Display();

	//head->LL_delete_back();
	//head->LL_delete_back();
	//head->LL_delete_back();
	//head->LL_delete_back();

	/*head->DLL_delete_position(5);
	head->SLL_delete_position(3);
	head->SLL_delete_position(2);
	head->SLL_delete_position(1);*/

	//head->SLL_delete_element(5);
	//head->Display();
	//head->SLL_delete_element(4);
	//head->Display();
	//head->SLL_delete_element(3);
	//head->Display();
	//head->SLL_delete_element(2);
	//head->Display();
	//head->SLL_delete_element(1);
	//head->Display();

	delete head;
}