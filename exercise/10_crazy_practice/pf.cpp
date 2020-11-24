#include <iostream>
using namespace std;

long powern(long _x, int n)
{
	long d = 1;
	while(n--){
		d *= _x;
	}
	return d;
}

int main(int argc, char const *argv[])
{
	int x, n;

	cout << "x=";
	cin >> x;
	cout << "n=";
	cin >> n;

	cout << powern(x, n);

	return 0;
}