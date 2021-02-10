#pragma once
#include <iostream>
#include <stack>
#include <stdbool.h>

using namespace std;
class StackString {
public:
	void Reverse(char[], int);
	bool isBalanced(char[], int);
};



void StackString::Reverse(char C[], int n) {
	stack<char> S;
	//loop for push
	for (int i = 0; i < n; i++) {
		S.push(C[i]);
	}
	//loop for pop
	for (int i = 0; i < n; i++) {
		C[i] = S.top(); //overwrite the character at index i
		S.pop(); //perform pop.
	}
}

bool StackString::isBalanced(char C[], int n) {
	stack<char> S;
	for (int i = 0; i < n - 1;) {
		if (C[i] == '(') {
			S.push(C[i]);
		}
		else if (C[i] == ')' && C[i-1] == '(') {
			S.pop();
		}
		else {
			return false;
		}
	}
	bool isEmpty = S.empty();
	return isEmpty;
}
