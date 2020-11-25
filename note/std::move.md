#  `std::move`

- 一旦开始更频繁地使用移动语义，您将开始发现要调用移动语义的情况，但是必须使用的对象是`L`值，而不是`R`值。

> 示例

```c++
#include <iostream>

template<typename T>
void swapnum(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    const char* x{"ab"};
    const char* y{"cd"};
    std::cout << "x:" << x << ",y:" << y << " => ";
    swapnum(x, y);
    std::cout << "x:" << x << ",y:" << y << std::endl;
    return 0;
}
```

- `std :: move`是一个标准库函数，仅用于单一目的-将其参数转换为`R`值。我们可以将一个l值传递给`std :: move`，它将返回一个`R`值引用。`std :: move`在实用程序头中定义。
- 在头文件<utility>中

> 示例

```c++
#include <iostream>
#include <utility>

template<typename T>
void swapnum(T& a, T& b)
{
    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    const char* x{"ab"};
    const char* y{"cd"};
    std::cout << "x:" << x << ",y:" << y << " => ";
    swapnum(x, y);
    std::cout << "x:" << x << ",y:" << y << std::endl;
    return 0;
}
```
