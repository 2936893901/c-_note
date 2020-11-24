#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int year;

	cout << "请输入年份:";
	cin >> year;

	cout << ((year%4 == 0) ? "是闰年" : "不是闰年");

	return 0;
}