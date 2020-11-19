# STL容器

- STL包含许多可以在不同情况下使用的不同容器类。通常，容器类分为三个基本类别：序列容器，关联容器和容器适配器。



## 序列容器

- 序列容器是保持容器中元素顺序的容器类。序列容器的定义特征是可以选择按位置插入元素的位置。

    > 从C ++ 11开始，`STL`包含6个序列容器：`std :: vector`，`std :: deque`，`std :: array`，`std :: list`，`std :: forward_list`和`std :: basic_string`。

### `std::vector`(向量)

- vector 是表示可以改变大小的数组的序列容器。

```c++
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	for (int i{0}; i < 6; ++i)
		v.push_back(6 - i);	// 在容器的最后一个元素之后添加一个新元素

	for (int j{0}; j < v.size(); ++j)
	{
		if (!v.empty())
			std::cout << v[j] << " ";
	}

	return 0;
}
```

----

 ### `std::deque` (双端队列)

- `deque（['dek]）`（双端队列）是`double-ended queue` 的一个不规则缩写。`deque`是具有动态大小的序列容器，可以在两端（前端或后端）扩展或收缩。

```c++
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> d;

	for (int i{0}; i < 5; ++i)
	{
		d.push_back(i);
		d.push_front(5 - i);
	}

	for (int j{0}; j < d.size(); ++j)
		std::cout << d[j] << " ";
    return 0;
}
````

## 关联容器

- 关联容器是在将这些输入插入容器时自动对其输入进行排序的容器。

## 容器适配器

- 容器适配器是适用于特定用途的特殊预定义容器。
