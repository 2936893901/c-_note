#include <iostream>
#include <cstring>

template<typename T>
T maxValue(T t1, T t2)
{
	return (t1 > t2) ? t1 : t2;
}

template<>
char * maxValue<char *> (char *c1, char *c2)
{
	return strcmp(c1, c2) >= 0 ? c1 : c2;
}

int main(int argc, char const *argv[])
{
	std::cout << maxValue(4, 6) << std::endl;
	std::cout << maxValue("abcd", "aa") << std::endl;
	return 0;
}
