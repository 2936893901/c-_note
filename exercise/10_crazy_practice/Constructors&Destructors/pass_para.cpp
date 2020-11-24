#include <iostream>

class A
{
	int a;
public:
	A(int x):a(x){std::cout << "a=" << a << std::endl;}
};

class B : public A
{
public:
	B(int x):A(x){std::cout << "constructor B" << std::endl;}
};

int main(int argc, char const *argv[])
{
	B b(10);

	return 0;
}