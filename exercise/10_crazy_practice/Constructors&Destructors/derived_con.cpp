#include <iostream>

class base
{
	int a;
public:
	base(int i):a(i){std::cout << "constructor base a = " << a << std::endl;}
};

class derived : public base
{
	int b;
public:
	//派生类构造函数的初始化列表
	derived(int x):base(x),b(x){std::cout << "constructor derived b = " << b << std::endl;}
};


int main(int argc, char const *argv[])
{
	derived d(10);
	return 0;
}