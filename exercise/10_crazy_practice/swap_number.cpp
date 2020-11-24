#include <iostream>

void swap(int& x, int& y);

int main(int argc, char const *argv[])
{
	int x1 = 10;
	int y1 = 5;
	swap(x1, y1);
	std::cout << "x1=" << x1 << ",y1=" << y1 << std::endl;
	return 0;
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
