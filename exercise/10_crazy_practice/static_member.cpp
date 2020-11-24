#include <iostream>

class App
{
	int x;
	static int global;	// 静态成员
public:
	static void setGlobal();	// 静态成员函数
	int getGlobal();
}a;

// 类的内部不能初始化静态函数及静态方法，用(::)来指明所属的类。
int App::global = 0;

void App::setGlobal()
{
	// 静态成员函数只能引用属于该类的静态数据成员或静态成员函数。
	global = 10;
	
	// x = 0;	//错误
}

int App::getGlobal()
{
	// 非静态成员函数既能调用静态成员或函数，又能调用非静态成员或函数
	return global;
}

int main(int argc, char const *argv[])
{
	App::setGlobal();
	std::cout << a.getGlobal();
	return 0;
}
