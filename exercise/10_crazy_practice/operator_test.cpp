#include <iostream>

class Time
{
public:
	Time(int a = 0, int b = 0, int c = 0):hh(a), mm(b), ss(c){}
	void operator++();
	void ShowTime();
private:
	int hh, mm, ss;

};
void Time::operator++()
{
	++ss;
	if (ss >= 60)
	{
		ss = 0;
		++mm;
		if (mm >= 60)
		{
			mm = 0;
			++hh;
			if (hh >= 24)
			{
				hh = 0;
			}
		}
	}
}

void Time::ShowTime()
{
	std::cout << "当前时间为:" << hh << "h " << mm << "m " << ss << "s" << std::endl;
}

int main(int argc, char const *argv[])
{
	Time t1(23, 59, 59);
	++t1;
	t1.ShowTime();

	return 0;
}
