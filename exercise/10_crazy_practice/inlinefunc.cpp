#include <iostream>

// 内联函数
inline double circle_area(float r)
{
  // 求圆面积
  return (3.1415 * r * r);
}

int main()
{
  float r1 = 10;
  std::cout << circle_area(r1);
  return 0;
}

