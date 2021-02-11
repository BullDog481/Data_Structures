#pragma once

class BSTP {
public:
	int data;
	BSTP* left = nullptr;
	BSTP* right = nullptr;
	BSTP* parent = nullptr;

	BSTP(int data) { this->data = data; }
};