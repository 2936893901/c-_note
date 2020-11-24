#include <iostream>

int i = 0;	// 全局变量

int main(int argc, char const *argv[])
{
	static int a;	// 局部静态变量
	int b = 10;	// 局部变量
	int c = 0;

	void other(void);

	a += 10;
	other();
	b += 20;
	other();
	i += 30;
	other();

	return 0;
}

void other(void)
{
	// 局部静态变量
	static int a = 2;
	static int b;

	a += 10;
	b += 100;
	i += 1000;

	std::cout << "a = " << a << ',' << "b = " << b << ',' << "i = " << i << std::endl;
}
