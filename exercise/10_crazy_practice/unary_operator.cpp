#include <iostream>

class Clock
{
public:
	int h, m, s;
	Clock(int x, int y, int z):h(x), m(y), s(z){}
	Clock operator++();
	// 友元函数
	friend Clock operator--(Clock &c);
	void showTime();
};

// ++运算符重载
Clock Clock::operator++()
{
	++s;
	if (s >= 60)
	{
		s = 0;
		++m;
		if (m >= 60)
		{
			m = 0;
			++h;
			if (h >= 24)
			{
				h = 0;
			}
		}
	}
	return *this;
}

// --运算符重载
Clock operator--(Clock &c)
{
	--c.s;
	if (c.s >= 60)
	{
		c.s = 0;
		--c.m;
		if (c.m >= 60)
		{
			c.m = 0;
			--c.h;
			if (c.h >= 24)
			{
				c.h = 0;
			}
		}
	}
	return c;
}

void Clock::showTime()
{
	std::cout << h << "h " << m << "m " << s << "s";
}

int main(int argc, char const *argv[])
{
	Clock c(10, 59, 59);
	++c;
	--c;
	c.showTime();
	return 0;
}
