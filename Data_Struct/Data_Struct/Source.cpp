#include "Linked_List.h";
#include "Doubly_Linked_List.h";
#include "Stack_Array.h";
#include "Stack_Linked_List.h";
#include <cstring>
#include <stdio.h>
#include "Stack_String.h";
#include "Queue.h";
#include "BST.h";
#include "BinaryTree.h";

//Driver code is contained here
int main(void) {
	//Driver Code for Linked List
	/*LinkedList* head = nullptr;
	std::cout << "How many numbers?" << std::endl;
	int n, i, x;
	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cout << "Enter the number \n";
		std::cin >> x;
		head = Insert_Begin(head, x);
		Print(head);
	}
	Insert_Nth(head, 3, 3);
	Print(head);
	int pos;
	std::cout << "Enter a position to delete: ";
	std::cin >> pos;
	Delete_Nth(head, pos);
	Print(head);
	head = Reverse(head);
	Print(head);
	Print_Recur(head);
	std::cout << std::endl;
	Print_Reverse(head);
	std::cout << std::endl;
	head = Reverse_Recur(head);
	Print(head);
	head = Reverse_Stack(head);
	Print(head);*/

	//Driver Code for Doubly Linked List
	/*DoublyLinkedList* head = nullptr;
	DoublyLinkedList myList = DoublyLinkedList();
	std::cout << "How many numbers?" << std::endl;
	int n, i, x;
	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cout << "Enter the number \n";
		std::cin >> x;
		head = myList.InsertAtHead(head, x);
	}
	myList.Print(head);
	myList.ReversePrint(head);*/

	//Driver code for Stack_Array
	/*Push(2); Print();
	Push(5); Print();
	Push(10); Print();
	Pop(); Print();
	Push(12); Print();*/

	//Driver code for Stack_Linked_List
	//TODO

	//Driver code for String_Stack
	/*char C[51];
	printf("Enter a string");
	std::cin >> C;
	StackString myStackString = StackString();
	myStackString.Reverse(C, strlen(C));
	printf("Output = %s\n", C);
	bool isBalanced = myStackString.isBalanced(C,strlen(C));
	std::cout << isBalanced << std::endl;*/

	//Driver code for Queue
	//TODO

	//Driver code for BST
	BST* rootPtr = nullptr;
	rootPtr = Insert(rootPtr, 15);
	rootPtr = Insert(rootPtr, 10);
	rootPtr = Insert(rootPtr, 20);
	rootPtr = Insert(rootPtr, 25);
	rootPtr = Insert(rootPtr, 8);
	rootPtr = Insert(rootPtr, 12);
	int number;
	std::cout << "Enter number to be searched for: ";
	std::cin >> number;
	if (Search(rootPtr, number) == true) std::cout << "Found\n";
	else std::cout << "Not Found\n";


	return 0;
}