#ifndef RESOURCES_H
#define RESOURCES_H

// 测试类
class Test
{
public:
	Test(){std::cout << "Test()\n";}
	~Test(){std::cout << "~Test()\n";}
	void print(){std::cout << "Now it's in the test\n";}
};

#endif
