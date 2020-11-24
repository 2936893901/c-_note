#include <iostream>

class A
{
public:
	virtual void func(){
		std::cout << "A::func" << std::endl;
	}
};

class B : public A
{
public:
	void func(){
		std::cout << "B::func" << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	B b;
	b.func();
	return 0;
}
