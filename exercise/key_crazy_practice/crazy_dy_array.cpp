#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
	char *pstr;
	const char *p = "hello";

	pstr = new char[strlen(p) + 1];

	// strncpy(str1, str2, size)函数，是将str2的值复制，在赋值给str1，复制大小为size
	strncpy(pstr, p, strlen(p));

	std::cout << pstr << std::endl;

	delete pstr, p;

	return 0;
}
