#include <iostream>
using namespace std;

// 学生结构体
struct student
{
	char name[20];
	char sex;
	int grade;
};

int main(int argc, char const *argv[])
{
	student s1 = {"小明", 'M', 3};
	cout << s1.name << endl;
	cout << s1.sex << endl;
	cout << s1.grade << endl;
	cout << sizeof(s1.name) << endl;
	return 0;
}
