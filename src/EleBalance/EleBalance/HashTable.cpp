#include "HashTable.h"
#include <cstring>
#include <iostream>

int& HashTable::operator[](char* a) {
	for (int i = 0; i < num; i++) {
		if ((e + i)->ele[0] == *a && (e + i)->ele[1] == *(a + 1)) {
			return (e + i)->num;
		}
	}

	element* new_e = new element[num + 1];
	memcpy(new_e, e, sizeof(element) * num);
	delete[] e;
	e = new_e;
	num++;
	(e + num - 1)->ele[0] = a[0];
	(e + num - 1)->ele[1] = a[1];
	(e + num - 1)->num = 0;
	return (e + num - 1)->num;
}

element& HashTable::operator[](int a) {
	return *(e + a);
}

HashTable::HashTable() {
	e = nullptr;
	num = 0;
}

int HashTable::ElementSearch(char* a) {
	for (int i = 0; i < num; i++) {
		if ((e + i)->ele[0] == *a && (e + i)->ele[1] == *(a + 1)) {
			return (e + i)->num;
		}
	}
	return 0;
}

void HashTable::HashCheck() {
	for (int i = 0; i < num; i++) {
		std::cout << (e + i)->ele << " ";
		std::cout << (e + i)->num << std::endl;
		//std::cout << num << std::endl;
	}
}

int HashTable::HashSzie() {
	return num;
}