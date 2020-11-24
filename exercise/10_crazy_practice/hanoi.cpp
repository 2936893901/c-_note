#include <iostream>
#include <cmath>
using namespace std;
void move(char a, char b);
void hanoi(int n, char a, char b, char c);
int main(int argc, char const *argv[])
{
	int n;
	cout << "Please input times:";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	cout << "It need " << pow(2, n) - 1 << " step";
	return 0;
}

void move(char a, char b)
{
	cout << a << "->" << b << endl;
}

void hanoi(int n, char a, char b, char c)
{
	if(n == 1)
		move(a, c);
	else
	{
		hanoi(n-1, a, c, b);
		move(a, c);
		hanoi(n-1, b, a, c);
	}
}