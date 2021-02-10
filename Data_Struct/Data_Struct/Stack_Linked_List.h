#pragma once
#include <stdbool.h>

class LinkedStack {
public:
	int value;
	LinkedStack* next = nullptr;

	LinkedStack(int value) { this->value = value; }
	LinkedStack* Push(LinkedStack*, int);
	LinkedStack* Pop(LinkedStack*);
	int Top(LinkedStack*);
	bool isEmpty(LinkedStack*);
};


LinkedStack* LinkedStack::Push(LinkedStack* top, int x) {
	LinkedStack* temp = new LinkedStack(x);
	temp->value = x;
	temp->next = top;
	top = temp;
	return top;
}

LinkedStack* LinkedStack::Pop(LinkedStack* top) {
	LinkedStack* temp;
	if (top == nullptr) return top;
	temp = top;
	top = top->next;
	delete temp;
	return top;
}

int LinkedStack::Top(LinkedStack* top) {
	int x = top->value;
	return x;
}

bool LinkedStack::isEmpty(LinkedStack* top) {
	if (top == nullptr) return true;
	else return false;
}