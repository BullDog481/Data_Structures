#pragma once

class DoublyLinkedList {
public:
	int value;
	DoublyLinkedList* next;
	DoublyLinkedList* prev;

	void Print(DoublyLinkedList* head);
	void ReversePrint(DoublyLinkedList* head);
	DoublyLinkedList* InsertAtHead(DoublyLinkedList* head, int x);
};

DoublyLinkedList* GetNewNode(int x) {
	DoublyLinkedList* newNode = new DoublyLinkedList;
	newNode->value = x;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	return newNode;
}

DoublyLinkedList* DoublyLinkedList::InsertAtHead(DoublyLinkedList* head, int x) {
	DoublyLinkedList* newNode = GetNewNode(x);
	if (head == nullptr) {
		head = newNode;
		return head;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
	return head;
}

void DoublyLinkedList::Print(DoublyLinkedList* head) {
	DoublyLinkedList* temp = head;
	std::cout << "Forward: ";
	while (temp != nullptr) {
		std::cout << " " << temp->value;
		temp = temp->next;
	}
	std::cout << std::endl;
}

void DoublyLinkedList::ReversePrint(DoublyLinkedList* head) {
	DoublyLinkedList* temp = head;
	if (temp == nullptr) return; //empty list, exit
	//Going to last Node
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	//Traversing backward using prev pointer
	std::cout << "Reverse: ";
	while (temp != nullptr) {
		std::cout << " " << temp->value;
		temp = temp->prev;
	}
	std::cout << std::endl;
}