#include <iostream>

class equal
{
public:
	equal operator=(const equal& e);
};

equal equal::operator=(const equal& e)
{
	std::cout << "e:";
	return e;
}

int main(int argc, char const *argv[])
{
	equal e1, e2;
	e1 = e2;
	e1.operator = (e2);
	return 0;
}
