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
#include <utility>	// for std::move function

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



- 当用`L`值填充容器的元素（例如`std :: vector`）时，我们还可以使用`std :: move`。

> 示例
```c++
#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> vet;
	std::string str1{"copy"};
	std::string str2{"move"};

	// 复制值
	std::cout << "\n---Copy value---\n";
	vet.push_back(str1);
	std::cout << "str1:" << str1 << ", vector:" << vet[0] << std::endl;


	// 移动值
	std::cout << "\n---Move value---\n";
	vet.push_back(std::move(str2));
	std::cout << "str2:" << str2 << ", vector:" << vet[1] << std::endl;
	return 0;
}
```

<font size="4" color=red>*只要我们想将l值视为r值，以调用移动语义而非复制语义，就可以使用`std :: move`。*</font>
