#include <iostream>

// 常引用做形参，在函数中不能更新 r所引用的对象。
void display(const int& x);

class A
{
public:
	A(int x, int y):i(x),j(y){}
	// 常成员函数说明格式：类型说明符  函数名（参数表）const;
	// 通过常对象只能调用它的常成员函数
	void printmsg() const;
private:
	int i,j;
};

void A::printmsg() const
{
	  std::cout << "I am const function" << std::endl;
}

int main(int argc, char const *argv[])
{
	int value = 10;
	display(value);
	A const a(2, 3);	// 常对象
	a.printmsg();
	return 0;
}

void display(const int& x)
{
	std::cout << x << std::endl;
}
