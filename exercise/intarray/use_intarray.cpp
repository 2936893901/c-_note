#include <iostream>
#include "IntArray.h"

int main(int argc, char const *argv[])
{
	IntArray a(8);
	for (int i = 0; i < 7; ++i)
		a[i] = i + 1;
	a.resize(10);

	a.insertBefore(2, 2);

	std::cout << a.getLength();
	return 0;
}