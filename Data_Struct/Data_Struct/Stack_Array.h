#pragma once
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
//Last in First Out Collection (LIFO)

//a list with the restriction that insertion and deletion can
//be performed from only one end, called the top
/*Operations:
* Push(x) -> void
* Pop() -> elem
* Top() -> elem
* IsEmpty() -> boolean
* These are all O(1)
*/
//Used for Function Calls/Recursion, implement undo operation in a text editor
//Can Determine Balanced Parentheses in a Source code using a stack for a compiler.

void Push(int x) {
	if (top == MAX_SIZE - 1) {
		std::cout << "Error: stack overflow\n";
		return;
	}
	A[++top] = x;
}

void Pop() {
	if (top == -1) {
		std::cout << "Error: No element to pop\n";
		return;
	}
	top--;
}

int Top() {
	return A[top];
}

void Print() {
	int i;
	std::cout << "Stack: ";
	for (i = 0; i <= top; i++) {
		std::cout << " " << A[i];
	}
	std::cout << std::endl;
}