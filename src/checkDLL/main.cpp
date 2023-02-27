#include <iostream>
#include <string>
#include "../EleBalance/EleBalance/Native.h"

#pragma comment(lib, "../../bin/EleBalance.lib")

int main() {
	char a[] = { "Cu+HNO3=Cu(NO3)2+NO2+H2O" };
	
	char* c = ElementBalance(a);
	
	std::string ans = c;
	std::cout << ans << std::endl;
	
}