#include <iostream>

void Exp()
{
	std::cout << "-----start-----\n";

	try{
		std::cout << "-----inside-----\n";
		throw "whhhh";
		std::cout << "-----after-----\n";
	}catch(double i){
		std::cout << "-----int----- :" << i << std::endl;
	}catch(const char * c){
		std::cout << "-----char*----- :" << c << std::endl;
	}

	std::cout << "-----end-----";
}

const int maxSize = 4;
class Empty{};
class Full{
public:
	void printmsg()
	{
		std::cout << "The stack is full\n";
	}
};

class Stack
{
	int top;
	int s[maxSize];
public:
	Stack():top(-1){}
	void push(int n)
	{
		if (top >= maxSize - 1)
			throw Full();
		else
			s[++top] = n;
	}
	int pop()
	{
		if (top <= -1)
		{
			throw Empty();
		}
		else
			return s[--top];
	}
};

int main(int argc, char const *argv[])
{
	// Exp();

	Stack s;

	try{
		for (int i = 0; i < 5; ++i)
			s.push(i);
	}catch(Full f){
		f.printmsg();
	}

	return 0;
}
