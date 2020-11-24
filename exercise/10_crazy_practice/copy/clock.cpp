#include <iostream>
#include "clock.h"

void Clock::SetTime(int a, int b, int c)
{
	// 这里加不加this->都一样
	a = this->hour;
	b = this->min;
	c = this->seconds;
}

void Clock::ShowTime()
{
	std::cout << this->hour << " h " << this->min << " m " << this->seconds << " s." << std::endl;
}

Clock::~Clock()
{
	std::cout << "……" << std::endl;
}

int main(int argc, char const *argv[])
{
	Clock c(1,2,3);
	c.ShowTime();

	// 复制构造函数调用
	Clock *c1 = &c;
	c1->ShowTime();

	// 同上
	Clock c2(*c1);
	c2.ShowTime();

	delete c1;

	return 0;
}
