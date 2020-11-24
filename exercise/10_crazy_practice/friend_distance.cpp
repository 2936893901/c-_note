#include <iostream>
#include <cmath>

//计算两点的距离
class Point
{
public:
	Point(int x = 0, int y = 0) : x(x),y(y){}
	// 声明友元函数
	friend float Distance(const Point& p1, const Point& p2);
private:
	int x,y;
};

float Distance(const Point& p1, const Point& p2)
{
	double x_axis = p1.x - p2.x;
	double y_axis = p1.y - p2.y;
	return sqrt(pow(x_axis, 2) + pow(y_axis, 2));
}

// 友元类
// 如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据
class A
{
	friend class B;
public:
	int x;
protected:
	void Display(){
		std::cout << "A::Display" << std::endl;
	}
private:
	int y;
};

class B
{
public:
	void setY(int i);
	void getD();
private:
	A a;
}b;

void B::setY(int i)
{
	a.y = i;
}

void B::getD()
{
	a.Display();
}


int main(int argc, char const *argv[])
{
	Point p1(1.0,2.0), p2(3.5, 7.0);
	std::cout << Distance(p1, p2) << std::endl;
	
	b.getD();
	return 0;
}
