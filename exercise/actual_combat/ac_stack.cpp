#include <iostream>

class obj
{
public:
	obj(){puts("obj()");}	// int puts(const char * str); 将字符串写入标准输出，返回值为整数
	~obj(){puts("~obj()");}
};

void foo(int n)
{
	obj o;
	if (n == 0)
		throw "you lost!";
}

// 不管是否发生了异常，obj类中的析构函数都会得到执行。
int main(void)
{
	try{
		foo(1);
		foo(0);
	}catch(const char* e){
		puts(e);
	}
	return 0;
}
