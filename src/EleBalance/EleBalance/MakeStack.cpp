#include "MakeStack.h"
#include <cstring>

MakeStackChar::MakeStackChar() {
	st = nullptr;
	p_top = st;
	high = 0;
}

void MakeStackChar::Push(char a) {
	char* new_st = new char[high + 1];
	memcpy(new_st, st, sizeof(char) * high);
	delete[] st;
	st = new_st;
	st[high] = a;
	p_top = st + high;
	high++;
}

void MakeStackChar::Push(char* a) {
	char* new_st = new char[high + 1];
	memcpy(new_st, st, sizeof(char) * high);
	delete[] st;
	st = new_st;
	st[high] = *a;
	p_top = st + high;
	high++;
}

char& MakeStackChar::Top() {
	return *p_top;
}

void MakeStackChar::Pop() {
	if (p_top != st) {
		high--;
		char* new_st = new char[high];
		memcpy(new_st, st, sizeof(char) * high);
		delete[] st;
		st = new_st;
		if (high > 0) p_top = st + high - 1;
		else p_top = st;
		
	}
	else if (p_top == st) {
		delete st;
		st = nullptr;
		high = 0;
	}
}

void MakeStackChar::Clear() {
	delete[] st;
	high = 0;
}

int MakeStackChar::StackSize() {
	return high;
}


//

MakeStackInt::MakeStackInt() {
	st = nullptr;
	p_top = st;
	high = 0;
}

void MakeStackInt::Push(int a) {
	int* new_st = new int[high + 1];
	memcpy(new_st, st, sizeof(int) * high);
	delete[] st;
	st = new_st;
	st[high] = a;
	p_top = st + high;
	high++;
}

void MakeStackInt::Push(int* a) {
	int* new_st = new int[high + 1];
	memcpy(new_st, st, sizeof(int) * high);
	delete[] st;
	st = new_st;
	st[high] = *a;
	p_top = st + high;
	high++;
}

int& MakeStackInt::Top() {
	return st[high - 1];
}

void MakeStackInt::Pop() {
	if (p_top != st) {
		high--;
		int* new_st = new int[high];
		memcpy(new_st, st, sizeof(int) * high);
		delete[] st;
		st = new_st;
		if (high > 0) p_top = st + high - 1;
		else p_top = st;

	}
	else if (p_top == st) {
		delete st;
		st = nullptr;
		high = 0;
	}
}

void MakeStackInt::Clear() {
	delete[] st;
	high = 0;
}

int MakeStackInt::StackSize() {
	return high;
}