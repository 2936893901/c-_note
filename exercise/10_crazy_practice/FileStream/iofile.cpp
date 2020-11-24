#include <iostream>
#include <fstream>
int main()
{
	std::fstream iofile;
	iofile.open("1.txt",std::ios::out);
	iofile << "张三" << " " << 78 << " " << 84 << " " << 65 << std::endl;
	iofile << "李四" << " " << 82 << " " << 93 << " " << 77 << std::endl;
	iofile << "王二麻子" << " " << 71 << " " << 69 << " " << 60 << std::endl;
	iofile << "张三丰" << " " << 89 << " " << 73 << " " << 82 << std::endl;
	iofile.close();

	iofile.open("1.txt", std::ios::in | std::ios::binary);
	char name[50];
	// 英语，数学，计算机
	int en, math, com;
	std::cout << "姓名\t " << "英语\t " << "数学\t " << "计算机 " << std::endl;
	iofile >> name;
	
	// 若关联流已抵达文件尾则返回 true 
	while(!iofile.eof()){
		iofile >> en >> math >> com;
		std::cout << name << "\t " << en << "\t " << math << "\t " << com << std::endl;
		iofile >> name;
	}
	iofile.flush();
	iofile.close();

	return 0;
}