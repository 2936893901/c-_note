#include <iostream>

class A
{
public:
	// 用纯虚函数实现抽象类
	virtual int func(int a) = 0;
};

class B : public A
{
public:
	int func(int a){
		return a;
	}
};

int main(int argc, char const *argv[])
{
	B b;
	std::cout << b.func(1);
	return 0;
}
