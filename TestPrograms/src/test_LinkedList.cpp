#include"LinkedList.h"

int main() {
	LinkedList* head = new LinkedList;
	head->LL_add_back(1);
	head->LL_add_back(2);
	head->LL_add_back(3);
	head->LL_add_back(4);

	head->Display();
}