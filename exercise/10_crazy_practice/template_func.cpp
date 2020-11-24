#include <iostream>

template<typename T>
T Max(T t1, T t2)
{
	return (t1 > t2) ? t1 : t2;
}

int main(int argc, char const *argv[])
{
	std::cout << "The maximum is " << Max(2, 3) << std::endl;
	std::cout << "The maximum is " << Max<char>('a', 'c') << std::endl;
	std::cout << "The maximum is " << Max(int(2.3), 4) << std::endl;
	return 0;
}
