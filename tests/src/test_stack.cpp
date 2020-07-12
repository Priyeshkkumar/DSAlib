#include"Stack.h"

int main() {
	//using stack with linked list therefore not passing size
	Stack* stack = new Stack;
	stack->Spush(1);
	stack->Spush(2);
	stack->Spush(3);
	stack->Spush(4);
	
	stack->Display();

	int popped;

	popped = stack->Spop();
	std::cout << std::endl << popped << " ";
	popped = stack->Spop();
	std::cout << std::endl << popped << " ";
	popped = stack->Spop();
	std::cout << std::endl << popped << " ";
	popped = stack->Spop();
	std::cout << std::endl << popped << " ";
	popped = stack->Spop();
	std::cout << std::endl << popped << " ";

	delete stack;
}