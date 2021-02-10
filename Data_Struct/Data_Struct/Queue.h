#pragma once
#include <stdbool.h>
//First In First Out (FIFO)
//Insertion happens from the rear or tail of the queue, removal happens at the head or front of the queue.
//Operations:
/* Enqueue(x) or Push(x)
* Dequeue() or Pop(x)
* front() or Peek() returns the element at the head of the queue
* IsEmpty()
* All O(1) Operations
* The following Queue is implemented by a Linked List
*/

class Queue {
public:
	int data;
	Queue* next = nullptr;

	Queue(int data) { this->data = data; }
};

Queue* front = nullptr;
Queue* rear = nullptr;

void Enqueue(int x) {
	Queue* temp = new Queue(x);
	temp->data = x;
	temp->next = nullptr;

	if (front == nullptr && rear == nullptr) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	Queue* temp = front;
	if (front == nullptr) return;
	if (front == rear) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
	}
	delete temp;
}

int Front() {
	Queue* temp = front;
	return temp->data;
}

bool isEmpty() {
	if (front == nullptr && rear == nullptr) return true;
	else return false;
}