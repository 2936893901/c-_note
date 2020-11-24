#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i, j, k, s;
	for(i = 1; i <= 4; i++)
	{
		for(j = 1; j <= 5; j++)
			cout << "-";
		for(k = 1; k <= 8-2*i; k++)
			cout << "-";
		for(s = 1; s <= 2*i; s++)
			cout << "*";
		cout << endl;
	}
	for(i = 1; i <= 3; i++)
	{
		for(j = 1; j <= 5; j++)
			cout << "-";
		for(k = 1; k <= 7-2*i; k++)
			cout << "*";
		cout << endl;
	}
	system("pause");
	return 0;
}