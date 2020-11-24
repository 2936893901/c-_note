#include <iostream>

class A
{
public:
	A(){std::cout << "constructor A" << std::endl;}
	A(int a){std::cout << a;}
};

class B
{
public:
	B(){std::cout << "constructor B" << std::endl;}
};

class C :public A, public B
{
public:
	C(){std::cout << "constructor C" << std::endl;}
};

class D : virtual public A
{
public:
	D(){std::cout << "constructor D" << std::endl;}
};

class E : public D
{
public:
	E(int i):A(i){std::cout << "constructor E" << std::endl;}	//虚基类由最终派生类初始化
};

/*
虚基类调用次序
	先调用虚基类的构造函数，再调用非虚基类的构造函数
	若同一层次中包含多个虚基类,这些虚基类的构造函数按它们的说明的次序调用
	若虚基类由非基类派生而来,则仍然先调用基类构造函数,再调用派生类构造函数
*/

int main(int argc, char const *argv[])
{
	C c;
	// E e(1);
	return 0;
}
