#include <iostream>

// 派生类构造函数调用顺序:基类->成员函数->派生类自身构造方法

class A
{
public:
	A(){std::cout << "constructor A" << std::endl;}
};

class B
{
public:
	B(){std::cout << "constructor B" << std::endl;}
};

class C : public B
{
public:
	C(){std::cout << "constructor C" << std::endl;}
	A a;
};

int main()
{
	C c;
	return 0;
}