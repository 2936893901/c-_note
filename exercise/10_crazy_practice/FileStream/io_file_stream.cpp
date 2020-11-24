#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	char ch;
	std::ofstream ofile("2.txt", std::ios::out | std::ios::binary);
	for (int i = 0; i <= 100; ++i)
	{
		if(i % 20 == 0)
			ofile.put('\n');
		ofile.put(i);
		ofile.put(' ');
	}
	ofile.close();

	std::ifstream ifile("2.txt", std::ios::in | std::ios::binary);
	while(ifile.get(ch)){
		std::cout << ch;
	}
	ifile.close();
	return 0;
}