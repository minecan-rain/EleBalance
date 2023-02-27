#pragma once

struct element {
	char ele[2];
	int num;
};

class HashTable {
private:
	element* e;
	int num;
public:
	//[] operator
	int& operator[](char* a);
	element& operator[](int a);

	//create the hash table
	HashTable();
	//HashTable(char* a);

	//to find whether the element has been in the hash table
	int ElementSearch(char* a);
	
	//check the table
	void HashCheck();

	//size
	int HashSzie();
};