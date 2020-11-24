#include <iostream>
#include <cstring>

struct employees
{
	const char *name;
	double salary;
	double &operator[](const char *n)
	{
		n = name;
		return salary;
	}

};

class SalMsg
{
	employees *emp;
	int max;
	int num;
public:
	SalMsg(){}
	SalMsg(int m = 0):max(m), num(0), emp(new employees[max]){}
	void display()
	{
		for (int i = 0; i < num; ++i)
			std::cout << emp[i].name << "\t" << emp[i].salary << std::endl;
	}
	double &operator[](const char *n)
	{
		employees *e;
		for (e = emp; e < emp + num; ++e)
		{
			// 用strcmp函数比较name和n的区别
			if (strcmp(e->name, n) == 0)
				return e->salary;
		}
		e = emp + (num++);
		e->name = new char[strlen(n) + 1];
		e->name = n;
		e->salary = 0;
		return e->salary;
	}
	~SalMsg(){delete emp;}
};

int main()
{
	SalMsg s(3);
	s["abc"] = 9000;
	s["qqq"] = 8000;
	s["swx"] = 7000;


	return 0;
}
