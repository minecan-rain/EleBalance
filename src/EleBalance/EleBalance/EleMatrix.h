#pragma once
#include <string>
#include "HashTable.h"

struct Matrix {
	std::string ele;
	HashTable Ht;
};

class EleMatrix {
private:
	Matrix* M;
public:

	EleMatrix();
	EleMatrix(int n);

	Matrix& operator[](int n);

};