#include <iostream>
extern "C"{
	#include "add.h"
}
using namespace std;

int main()
{
	cout << add(1, 3);
	return 0;
}