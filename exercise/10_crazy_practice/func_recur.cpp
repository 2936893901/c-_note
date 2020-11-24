#include <iostream>
using namespace std;

// n阶乘
int func1(int n)
{
	if (n == 0)
		return 1;
	else
		return n * func1(n - 1);
}

// x的n次方
int func2(int x, int n)
{
	if (n == 0)
    	return 1;
  	else
    	return x * func2(x, n - 1);
}

int main()
{
	int x;
	int branch;
	cout << "Choose factorial(0) or n power(1):";
	cin >> branch;
	if (branch == 0)
	{
		cout << "Now let's take the factorial" << endl;
		cout << "Please enter x(x>=0):";
		cin >> x;
		if (x >= 0)
	  		cout << "x! =" << func1(x) << endl;
		else
		  cout << "Please enter an integer";
	}
	else if ( branch == 1)
	{
		int n;
		cout << "Now let's take the n power" << endl;
		cout << "Please enter x(x>=0):";
		cin >> x;
		cout << "Please enter n(n>=0):";
		cin >> n;
		if (x >= 0)
		  	cout << "x^n =" << func2(x, n) << endl;
		else
		  	cout << "Please enter an integer";
	}
	else
		cout << "Please enter zero or one" << endl;



	return 0;
}
