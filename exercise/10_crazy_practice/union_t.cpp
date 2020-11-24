#include <iostream>
using namespace std;

union mm
{
	struct{int x; int y;}s;
	int z;
}m1;

int main(int argc, char const *argv[])
{
	m1.s.x = 1;
	m1.s.y = 2;
	m1.z = 0;


	printf("%d %d %d\n", m1.s.x, m1.s.y, m1.z);
	return 0;
}
