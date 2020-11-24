#include <iostream>

// 当同时存在直接基类和间接基类时，每个派生类只负责其直接基类的构造。

class A
{
public:
	A(){std::cout << "constructor A" << std::endl;}
};

class B :public A
{
public:
	B():A(){std::cout << "constructor B" << std::endl;}
};

class C : public B
{
public:
	C():B(){std::cout << "constructor C" << std::endl;}
};

int main(int argc, char const *argv[])
{
	C c;
	return 0;
}
