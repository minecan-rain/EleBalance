#pragma once


class MakeStackChar {
private:
	char* st;
	char* p_top;
	int high;
public:
	MakeStackChar();

	void Push(char a);
	void Push(char* a);

	char& Top();

	void Pop();

	void Clear();

	int StackSize();
};

class MakeStackInt {
private:
	int* st;
	int* p_top;
	int high;
public:
	MakeStackInt();

	void Push(int a);
	void Push(int* a);

	int& Top();

	void Pop();

	void Clear();

	int StackSize();
};