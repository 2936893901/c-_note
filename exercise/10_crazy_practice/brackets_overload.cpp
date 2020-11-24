#include <iostream>

class brackets
{
public:
	int operator()(int i = 0)
	{
		return i+1;
	}
	int operator[](int j)
	{
		return j+1;
	}
};

int main(int argc, char const *argv[])
{
	brackets b1;

	std::cout << b1[b1(1)];

	return 0;
}
