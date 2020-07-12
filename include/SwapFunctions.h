#pragma once
#include"Algos.h"

static void swap_sorting(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

static void swap_sorting(Node* a, Node* b) {
	int temp = a->GetNodeValue();
	a->SetNodeValue(b->GetNodeValue());
	b->SetNodeValue(temp);
}