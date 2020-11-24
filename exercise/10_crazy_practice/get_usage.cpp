#include <iostream>

int main()
{
	char a, b, c[2], d[3], e[4], f[5];
	std::cin.get(a);
	b = std::cin.get();

	// std::cin.get(arrayname,size)  把字符输入到arrayname中，长度不超过size
	std::cin.get(c, 3);

	/*
		用法：std::cin.get(arrayname,size,s)
		把数据输入到arrayname字符数组中，当到达长度size时结束或者遇到字符s时结束
		arrayname必须是字符数组，即char arrayname[]类型，不可为string类型
	*/
	std::cin.get(d, 2, '.');

	/*
		std::cin.getline(arrayname,size)与std::cin.get(arrayname,size)的区别
			- std::cin.get(arrayname,size)当遇到[Enter]时会结束目前输入，他不会删除缓冲区中的[Enter]
			- std::cin.getline(arrayname,size)当遇到[Enter]时会结束当前输入，但是会删除缓冲区中的[Enter]
	*/
	std::cin.getline(e, 4);
	/*
    	std::cin.getline(arrayname,size,s)与std::cin.gei(arrayname,size,s)的区别
		    - std::cin.getline(arrayname,size,s)当遇到s时会结束输入，并把s从缓冲区中删除
		    - std::cin.get（arrayname,size,s）当遇到s时会结束输入，但不会删除缓冲区中的s
	*/
	std::cin.getline(f, 5, '.');

	std::cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << ",e=" << e;
	return 0;
}
