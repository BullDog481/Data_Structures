#include <iostream>
#include <stack>
#pragma once

class LinkedList {
public:
	int value;
	LinkedList* next = nullptr;

	LinkedList(int value) { this->value = value; }
};

//Insert a node at the beginning of a linked list
LinkedList* Insert_Begin(LinkedList* head, int x) {
	LinkedList* temp = new LinkedList(x);
	temp->value = x;
	temp->next = head;
	head = temp;
	return head;
}

//insert a node at nth position of a linked list
LinkedList* Insert_Nth(LinkedList* head, int x, int pos) {
	LinkedList* temp = new LinkedList(x);
	temp->value = x;
	temp->next = nullptr;
	if (pos == 1) {
		temp->next = head;
		head = temp;
		return head;
	}
	LinkedList* temp2 = head;
	for (int i = 0; i < pos - 2; i++) {
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;
	return head;
}

//delete a node at nth position of a linked list
LinkedList* Delete_Nth(LinkedList* head, int pos) {
	LinkedList* temp = head;
	if (pos == 1) {
		head = temp->next;
		delete temp;
		return head;
	}
	for (int i = 0; i < pos - 2; i++) {
		temp = temp->next;
	}
	//temp points to (n-1)th node
	LinkedList* temp2 = temp->next;
	temp->next = temp2->next; //(n+1)th node;
	delete temp2;
	return head;
}

//reverse a linked list iteratively
LinkedList* Reverse(LinkedList* head) {
	LinkedList* next = nullptr;
	LinkedList* prev;
	LinkedList* current;
	current = head;
	prev = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

//Print a linked list using recursion
void Print_Recur(LinkedList* head) {
	if (head == nullptr) return;
	std::cout << " " << head->value;
	Print_Recur(head->next);
}

//print a linked list in reverse order using recursion
void Print_Reverse(LinkedList* head) {
	if (head == nullptr) return;
	Print_Reverse(head->next);
	std::cout << " " << head->value;
}

//Reverse a linked list using recursion
LinkedList* Reverse_Recur(LinkedList* head) {
	if (head->next == nullptr) {
		head = head;
		return head;
	}
	Reverse_Recur(head->next);
	LinkedList* q = head->next;
	q->next = head;
	head->next = nullptr;
	return head;
}

void Print(LinkedList* head) {
	LinkedList* temp = head;
	std::cout << "List is: ";
	while (temp != nullptr) {
		std::cout << " " << temp->value;
		temp = temp->next;
	}
	std::cout << std::endl;
}


//Reverse a linked list using a stack
/*LinkedList* Reverse_Stack(LinkedList* head) {
	if (head == nullptr) return head;
	stack<LinkedList*> S;
	LinkedList* temp = head;
	while (temp != nullptr) {
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top(); head = temp;
	S.pop();
	while (!S.empty()) {
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = nullptr;
}*/

