#include <iostream>

class water
{
public:
	void operator()(int x);
};

void water::operator()(int x)
{
	std::cout << x;
}

int main(int argc, char const *argv[])
{
	water w1;
	w1.operator()(3);
	return 0;
}
