#include <iostream>
#include <string>
using namespace std;

enum week{
	mon = 1,tues,wednew,thurs,fri,satur,sun
};

enum class weekday : char{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int main(int argc, char const *argv[])
{
	cout << week::fri << endl;
	return 0;
}