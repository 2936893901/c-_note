#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <initializer_list>
#include <vector>

template<typename T>
class Employee
{
	std::vector<T> t;
public:
	Employee(){}
	Employee(std::initializer_list<T> n) : t(n){}
	void append(std::initializer_list<T> n)
	{
		t.insert(n.end(), n.begin(), n.end());
	}
	T operator[](int index)
	{
		if (index > t.size() - 1){
			throw "error:vector index exceeds range\n";
			return 0;
		}
		else
			return t[index];
	}
};

int main(int argc, char const *argv[])
{
	system("chcp 63001");
	Employee<const char *> name = {"aa", "bb", "cc"};
	Employee<int> age = {22, 25, 33};
	Employee<double> sal = {5000, 6000, 7000};

	std::ofstream out("2.txt", std::ios::out | std::ios::binary);
	out.seekp(std::ios::end);
	out.write((char*)&name, sizeof(name));
	out.write((char*)&age, sizeof(age));
	out.write((char*)&sal, sizeof(sal));

	out.close();

	char data[50];
	std::ifstream in("2.txt", std::ios::in | std::ios::binary);
	in >> data;
	std::cout << data;
	in.close();
	
	// try{
	// const char *n = name[3];
	// std::cout << n;
	// }catch(const char * e){
	// 	std::cout << e;
	// }
	return 0;
}
