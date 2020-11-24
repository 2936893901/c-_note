#include <iostream>
#define pi 3.14159626

/*
类型转换函数没有参数。
类型转换函数没有返回类型。
类型转换函数必须返回将要转换成的type类型数据。
*/

class Circle
{
	double r;
public:
	Circle(double a):r(a){}
	operator int(){return (int)(r);}
	operator float(){return 2 * pi * r;}
	operator double(){return (float)(pi * r * r);}
};

int main(int argc, char const *argv[])
{
	Circle c(4);
	int r = c;
	std::cout << r << std::endl;
	double s = c;
	std::cout << s << std::endl;
	float z = c;
	std::cout << z << std::endl;

	return 0;
}
