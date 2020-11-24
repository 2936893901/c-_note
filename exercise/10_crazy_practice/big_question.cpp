/*
一圆型游泳池，现在需在其周围建一圆型过道，并在其四周围上栅栏。栅栏价格为35元/米，过道造价为20元/平方米。
过道宽度为3米，游泳池半径由键盘输入。要求编程计算并输出过道和栅栏的造价。
图形描述：大圆嵌套小圆：
小圆在大圆中间，小圆为游泳池，大圆与小圆间隔为过道。
*/

#include <iostream>
#define PI 3.14159625

// 定义常量､
const int corridorPrice = 20;
const int fencePrice = 35;

// 计算过道的总价
double corridor_price(double radius);

// 计算栅栏的总价
inline double fence_price(double radius);

int main(int argc, char const *argv[])
{
  // 输入并接收泳池半径
	double radius;
	std::cout << "Please enter pool radius:";
	std::cin >> radius;
  
  // 输出过道和栅栏的造价
	std::cout << "Cost of corridor:￥" << corridor_price(radius) << std::endl;
	std::cout << "Cost of fence:￥" << fence_price(radius) << std::endl;

	return 0;
}

double corridor_price(double radius)
{
	double r = radius + 3;
	double pool_area = radius * radius * PI;
	double long_area = r * r * PI;
	return (long_area - pool_area) * corridorPrice;
}

inline double fence_price(double radius)
{
	return 2 * PI * radius * fencePrice;
}
