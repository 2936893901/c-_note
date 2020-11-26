# STL标准模板库

## `std :: vector`

- 在C ++ 03中引入，`std::vector`提供了处理其自身的内存管理的动态数组功能。这意味着您可以创建在运行时设置长度的数组，而不必使用`new`和显式分配和取消分配内存`delete`。 `std::vector`位于<vector>标头中。

- 声明`std::vector`

	```c++
	#include <vector>
	
	std::vector<int> vet1;
	std::vector<int> vet2{1, 2, 3};
	
	// 与std::array一样，从c++ 17开始类型可以被省略
	std::vector vet3{1, 2, 3};
	```
	
	- 请注意，在未初始化和已初始化的情况下，都不需要在编译时包括数组长度。这是因为`std::vector`将根据请求动态为其内容分配内存。

- 可以通过`[]`运算符（不进行边界检查）或`at()`函数（进行边界检查）来访问数组元素：
    ```c++
vet[0] = 2;	//不执行边界检查
    vet.at(1) = 3;	//执行边界检查
    ```

### 自清理可防止内存泄漏

- 当向量变量超出范围时，它将自动取消分配其控制的内存（如有必要）。这不仅方便（因为您不必自己做），还有助于防止内存泄漏。

```c++
void dosometing(bool d)
{
    int *arr{new int[2]{1, 2}};
    
    if(d)
        return;
    
    delete[] arr;	// 当d为true时，arr将永不删除，造成内存泄漏
}
```

- 如果`arr`为`std::vector`，则不会发生这种情况，因为一旦`array`超出范围，内存将被重新分配（无论该函数是否提前退出）。

### 向量记住它们的长度

- 与内置动态数组不同，内置动态数组不知道它们指向的数组的长度，`std :: vector`跟踪其长度。通过`size()`函数返回长度。

```c++
std::vector<int> vet{1, 2, 3};
vet.size();
```

### 调整向量大小

- 调整内置动态分配数组的大小很复杂。调整大小`std::vector`与调用`resize()`函数一样简单。

```c++
std::vector<int> vet{1, 2};
vet.resize(3);
```

> 这里有三件事要注意。首先，当我们调整向量的大小时，现有的元素值将被保留！其次，将新元素初始化为该类型的默认值，最后调整向量的大小在计算上是昂贵的，因此您应努力减少这样做的次数。



### 压实bool

- `std::vector`<bool>类型有一个特殊的实现，它将8个布尔值压缩为一个字节！这发生在幕后，并且不会改变您使用`std :: vector`的方式。

    > 示例

    ```c++
    #include <iostream>
    #include <vector>

    int main(int argc, char const *argv[])
    {
        std::vector<bool> vet{false, true, false, true, false};
        std::cout << "The length is " << vet.size();
        return 0;
    }
    ```

