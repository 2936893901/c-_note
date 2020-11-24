#include <iostream>

class Base
{
private:
	int a;
protected:
	int b;
public:
	int c;
	void setA(int x){a = x;}
	int getA(){return a;}
};

class Derived1 : public Base
{
public:
	void getValue(){
		// a = 1;	// error: 派生类不可访问基类私有成员
		setA(1);
		b = 2;
		c = 3;
	}
};

/*
派生方式为protected的继承称为保护继承，在这种继承方式下，
基类的public成员在派生类中会变成protected成员，
基类的protected和private成员在派生类中保持原来的访问权限
*/

class Derived2 : protected Base
{
public:
	void getValue(){
		b = 5;
		c = 6;
	}
};

//私有继承
//基类的中的public成员在派生类中是private, private成员在派生类中不可访问。

class Derived3 : private Base
{
public:
	// void setC(int x){c = x;}	// error:基类中的成员都是私有成员无访问权限
};

int main(int argc, char const *argv[])
{
	Derived1 d1;
	d1.getValue();

	Derived2 d2;
	d2.getValue();
	return 0;
}
