#pragma once
#include <iostream>
#include <queue>

using namespace std;

class BinaryTree {
public:
	char data;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;

	BinaryTree(char data) { this->data = data; }
};

//Depth First Search O(n) Time, O(n) space where n is the number of nodes in the tree
void LevelOrder(BinaryTree* root) {
	if (root == nullptr) return;
	queue<BinaryTree*> Q;

	Q.push(root);

	while (!Q.empty()) {
		BinaryTree* current = Q.front();
		cout << current->data << " ";
		if (current->left != nullptr) Q.push(current->left);
		if (current->right != nullptr) Q.push(current->right);
		Q.pop(); //removing the element at the front
	}

}

//Breadth First Search - Preorder O(n) Time, O(h) space "", h is height of the tree
//Worst case O(n) space complexity, best/average case complexity O(log n) to base 2.
void Preorder(BinaryTree* root) {
	if (root == nullptr) return;
	printf("%c ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BinaryTree* root) {
	if (root == nullptr) return;
	Inorder(root->left);
	printf("%c ", root->data);
	Inorder(root->right);
}

void Postorder(BinaryTree* root) {
	if (root == nullptr) return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ", root->data);
}