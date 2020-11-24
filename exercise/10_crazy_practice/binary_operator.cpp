#include <iostream>

class ufunc
{
	int x;
public:
	ufunc(int i = 0):x(i){}
	ufunc operator+(ufunc &u);
	// 通过友元函数重载
	friend ufunc operator-(ufunc &u1, ufunc &u2);
	ufunc operator*(ufunc &u);
	// 通过友元函数重载
	friend ufunc operator/(ufunc &u1, ufunc &u2);

	void out(){std::cout << x << std::endl;}
};

ufunc ufunc::operator+(ufunc &u)
{
	return ufunc(x+u.x);
}

ufunc operator-(ufunc &u1, ufunc &u2)
{
	return ufunc(u1.x-u2.x);
}

ufunc ufunc::operator*(ufunc &u)
{
	return ufunc(x*u.x);
}

ufunc operator/(ufunc &u1, ufunc &u2)
{
	return ufunc(u1.x/u2.x);
}

int main(int argc, char const *argv[])
{
	ufunc u1(4);
	ufunc u2(2);

	(u1+u2).out();

	(u1-u2).out();

	(u1*u2).out();

	(u1/u2).out();

	return 0;
}
