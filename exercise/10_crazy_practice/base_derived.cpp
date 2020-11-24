#include <iostream>

class A
{
	int a;
public:
	void seta(int i){a = i;}
	int geta(){return a;}
};

class B : public A
{
	int b;
public:
	void setb(int i){b = i;}
	int getb(){return b;}
};

// void func1(A a, int x)
// {
// 	a.seta(x);
// }
// void func2(A *a, int x)
// {
// 	a->seta(x);
// }
// void func3(A &a, int x)
// {
// 	a.seta(x);
// }

int main(int argc, char const *argv[])
{
	A a1, *pa1;
	B b1, *pb1;
	a1.seta(5);
	b1.setb(10);
	pb1 = &b1;
	std::cout << a1.geta() << std::endl;
	std::cout << b1.getb() << std::endl;
	// std::cout << pa1->geta() << std::endl;
	// std::cout << pb1->getb() << std::endl;
	return 0;
}
