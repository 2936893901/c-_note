#include <iostream>

class A
{
	int x;
public:
	A(int i = 0):x(i){std::cout << "A..." << std::endl;}
};

class B
{
	int y;
public:
	B(int i = 0):y(i){std::cout << "B..." << std::endl;}
};

class C : public A
{
	B b1;
	B *pb2 = new B(3);
public:
	C():A(1),b1(2)
	{
		std::cout << "C...";
	}
};

int main(int argc, char const *argv[])
{
	C c;
	return 0;
}