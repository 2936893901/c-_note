#include <iostream>
#include <cmath>

class Clock
{
	int hour, min, seconds;
public:
	Clock(int h = 0, int m = 0, int s = 0);
	void ShowTime();
	Clock &operator++();
	Clock operator++(int);
	// Clock operator+(const Clock &c, int s);
};

Clock::Clock(int h, int m, int s)
{
	if (h > 0 && h < 24 && m > 0 && m < 60 && s > 0 && s < 60)
	{
		hour = h;
		min = m;
		seconds = s;
	}
	else
		std::cout << "Input format error" << std::endl;
}

void Clock::ShowTime()
{
	std::cout << "hour:" << hour << "\tmin:" << min << "\tseconds:" << seconds << std::endl;
}

Clock &Clock::operator++()
{
	++seconds;
	if (seconds >= 60)
	{
		seconds = 0;
		++min;
		if(min >= 60)
		{
			min = 0;
			++hour;
			if (hour >= 24)
				hour = 0;
		}
	}
	return *this;
}

Clock Clock::operator++(int)
{
	return ++(*this);
}

// Clock Clock::operator+(const Clock &c, int s)
// {

		// return *this;
// }

int main(int argc, char const *argv[])
{
	Clock c(12,59,59);
	++c;
	c++;
	c.ShowTime();

	return 0;
}
