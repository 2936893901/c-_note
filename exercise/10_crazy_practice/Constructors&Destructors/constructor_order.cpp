#include <iostream>

/*
先构造成员
再构造自身（调用构造函数）
*/

class A
{
public:
	A(){std::cout << "Constructor A" << std::endl;}
	~A(){std::cout << "Destructor A" << std::endl;}
};

class B
{
public:
	A a;
	B(){std::cout << "Constructor B" << std::endl;}
	~B(){std::cout << "Destructor B" << std::endl;}
};

int main()
{
	B b;
	return 0;
}