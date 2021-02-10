#pragma once
#include <algorithm>
#include <limits.h>

class BST {
public:
	int data;
	BST* left = nullptr;
	BST* right = nullptr;

	BST(int data) { this->data = data; }
};

/*BST* rootPtr; //to store address of the root node (pointer to root)
BST* rootPtr = nullptr;*/
BST* GetBSTNode(int);
//Function to insert in BST, returns address of root node
BST* Insert(BST* rootPtr, int data) {
	if (rootPtr == nullptr) { //empty tree
		rootPtr = GetBSTNode(data);
	}
	else if (data <= rootPtr->data) {
		rootPtr->left = Insert(rootPtr->left, data);
	}
	else {
		rootPtr->right = Insert(rootPtr->right, data);
	}
	return rootPtr;
}

BST* GetBSTNode(int data) {
	BST* newNode = new BST(data);
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

bool Search(BST* rootPtr, int data) {
	if (rootPtr == nullptr) return false;
	else if (rootPtr->data == data) return true;
	else if (data <= rootPtr->data) return Search(rootPtr->left, data);
	else return Search(rootPtr->right, data);
}

int FindMin(BST* rootPtr) {
	if (rootPtr == nullptr) {
		std::cout << "Error: Tree is empty\n";
		return -1;
	}
	while (rootPtr->left != nullptr) {
		rootPtr = rootPtr->left;
	}
	return rootPtr->data;
}

int FindMax(BST* rootPtr) {
	if (rootPtr == nullptr) {
		std::cout << "Error: Tree is empty\n";
		return -1;
	}
	while (rootPtr->right != nullptr) {
		rootPtr = rootPtr->right;
	}
	return rootPtr->data;
}

int FindMin_Recur(BST* rootPtr) {
	if (rootPtr == nullptr) {
		std::cout << "Error: Tree is empty\n";
		return -1;
	}
	else if (rootPtr->left == nullptr) {
		return rootPtr->data;
	}
	return FindMin_Recur(rootPtr->left);
}


//O(n) time complexity, O(n) space complexity
int FindHeight(BST* root) {
	if (root == nullptr) return -1;
	return std::max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

bool IsSubtreeLesser(BST* root, int value) {
	if (root == nullptr) return true;
	if (root->data <= value && IsSubtreeLesser(root->left, value)
		&& IsSubtreeLesser(root->right, value)) return true;
	else return false;
}

bool IsSubtreeGreater(BST* root, int value) {
	if (root == nullptr) return true;
	if (root->data > value && IsSubtreeGreater(root->left, value)
		&& IsSubtreeGreater(root->right, value)) return true;
	else return false;
}

//Check if a tree is a binary search tree -O(n^2) time, O(n) space, n nodes in tree
bool IsBinarySearchTree(BST* root) {
	if (root == nullptr) return true;
	if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data)
		&& IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
		return true;
	else return false;
}

//This algorithm uses less space for the recursive calls - O(n) time, O(n) space
bool IsBSTUtil(BST* root, int minValue, int maxValue) {
	if (root == nullptr) return true;
	if (root->data > minValue
		&& root->data < maxValue
		&& IsBSTUtil(root->left, minValue, root->data)
		&& IsBSTUtil(root->right, root->data, maxValue))
		return true;
	else return false;
}

bool IsBinarySearchTree(BST* root) {
	return IsBSTUtil(root, INT_MIN, INT_MAX);
}

BST* Delete(BST* root, int data) {
	if (root == nullptr) return root; //base case
	//find the data
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else { //data is found and can be deleted
		//Case 1: No Child
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
		} //Case 2: One Child
		else if (root->left == nullptr) {
			BST* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			BST* temp = root;
			root = root->left;
			delete temp;
		}
		//Case 3: 2 Children
		else {
			int temp = FindMin(root->right);
			root->data = temp;
			root->right = Delete(root->right, temp);
		}
	}
	return root;
}