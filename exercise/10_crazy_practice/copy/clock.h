#ifndef CLOCK
#define CLOCK
class Clock
{
public:
	Clock(int a = 0, int b = 0, int c = 0):hour(a), min(b), seconds(c){};
	// Clock(Clock& c);
	~Clock();
	void SetTime(int a = 0, int b = 0, int c = 0);
	void ShowTime();
private:
	int hour, min, seconds;
};

#endif