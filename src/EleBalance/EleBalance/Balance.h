#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "HashTable.h"
#include "MakeStack.h"
#include "EleMatrix.h"



class Balance {
private:
	int NumOfChemical;
	int place;
	
	std::string eq;
	std::string left;
	std::string right;
	HashTable le;
	HashTable ri;
public:
	//get the chemical equation
	Balance();
	Balance(std::string a);

	//divide equation
	void Divide();
	
	//same element
	int Compare();

	//make hash table
	HashTable make_the_table(std::string str);

	//Balance equation
	std::string BlanceEquation();

	//low tran determinant
	int determinant_change(int h, int l, int** mt);
	void swap(int* a, int* b, int n);
	int deter_value(int** mt, int s, int n);
	int gcd(int a, int b);

	//int to string
	std::string IntToString(int n);

	//check
	void ElementCheck();
	void ChemicalCheck();
};
