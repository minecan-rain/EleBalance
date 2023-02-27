#include <iostream>
#include "HashTable.h"
#include "MakeStack.h"
#include "Balance.h"
#include "Native.h"


HEAD char* CallingConvention ElementBalance(char* c) {
	std::string s = c;
	std::string ans;
	
	Balance Ans(s);
	Ans.Divide();	
	if (Ans.Compare() == 1)ans = Ans.BlanceEquation();
	else ans = "ERROR";
	int length = ans.size();
	char* e = new char[length];
	for (int i = 0; i < length; i++) {
		e[i] = ans[i];
	}
	
	return e;
}