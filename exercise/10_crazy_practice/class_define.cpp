#include <iostream>
class c1;	// 前向引用声明

// 错误：类c1的声明不完善
// class c2
// {
// 	c1 c;
// };

class c1
{
	int x;
};

class c3
{
	c1* c;	// 正确：经过前向引用声明，可以声明Fred类的对象指针
};

int main(int argc, char const *argv[])
{
	std::cout << "TEST TEST TEST !!!";
	return 0;
}
