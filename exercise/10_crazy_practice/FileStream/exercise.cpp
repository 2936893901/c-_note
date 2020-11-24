#include <iostream>
#include <vector>
#include <fstream>

class Person
{
	const char *name;
	const char *id;
	const char *addr;
public:
	Person(){}
	Person(const char *n, const char *i, const char *a) : name(n), id(i), addr(a){}
	void display(){
		std::cout << "name: " << name << "\tid: " << id << "\taddr: " << addr << std::endl;
	}
};

int main()
{
	std::vector<Person> v;

	// 声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素
	std::vector<Person>::iterator pos;
	char ch;

	// 以二进制追加写打开文件
	std::ofstream out("person.txt", std::ios::out | std::ios::app | std::ios::binary);
	char n[10], i[10], a[50];
	std::cout << "-----输入个人档案-----\n";

	do{
		std::cout << "name:";
		std::cin >> n;
		std::cout << "id:";
		std::cin >> i;
		std::cout << "address:";
		std::cin >> a;
		Person ps(n, i, a);
		out.write((char *)&ps, sizeof(ps));
		std::cout << "Enter another person(y/n)?";
		std::cin >> ch;
	}while(ch == 'y');

	out.close();

	// 打开文件
	std::ifstream in("person.txt", std::ios::in | std::ios::binary);
	Person p;
	in.read((char *)&p, sizeof(p));
	while(!in.eof()){
		v.push_back(p);
		in.read((char *)&p, sizeof(p));
	}

	std::cout << "-----数据读出-----\n";
	pos = v.begin();
	for (pos = v.begin(); pos != v.end(); ++pos)
		(*pos).display();
	in.close();

	return 0;
}