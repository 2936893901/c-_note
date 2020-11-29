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



### 常用函数

#### `insert`

- 在指定的插入元件之前新元素扩展位置，有效地增加了容器的尺寸由插入元件的数量。

```c++
constexpr iterator insert( iterator pos, const T& value );
```

- 参数

  - `pos`: 将内容插入到其前的迭代器。 `pos` 可为`end() `迭代器
  
  - `value`: 要插入的元素值
  
    > 示例
    
    ```c++
    #include <iostream>
    #include <vector>
    
    int main()
    {
        std::vector<int> vet{1, 2, 3, 4};
        std::vector<int>::iterator it{vet.end()};
        // auto it{vet.end()};
        
        vet.insert(it, 2, 9);
        retutn 0;
    }
    ```

#### `push_back`

- 在向量的末尾，在向量的最后一个元素之后添加一个新元素。插入值的内容被复制（或移动）到新元素。

```c++
void push_back（const value_type＆val;
void push_back（value_type && val;
```

- 参数
  - `val`:要复制（或移动）到新元素的值。

  > 示例

  ```c++
  #include <iostream>
  #include <vector>
  
  int main()
  {
      std::vector<int> vet{};
      vet.push_back(1);
      return 0;
  }
  ```



#### `pop_back`

- 删除向量中的最后一个元素，有效地将容器大小减小了一个。

  > 示例

  ```c++
  #include <iostream>
  #include <vector>
  
  int main()
  {
      std::vector<int> vet{1};
      vet.pop_back();
      return 0;
  }
  ```



##  `std::string`和`std::wstring`

- 标准库中的所有字符串功能都位于<string>头文件中。要使用它，只需包含字符串标题：

```c++
#include <string>
```

- `std :: string`用于标准`ascii`和`utf-8`字符串。`std :: wstring`用于宽字符/ `unicode`（`utf-16`）字符串。

### 常用函数

#### `empty()`

- 返回一个布尔值，指示字符串是否为空

> 示例

```c++
std::string str{};
str.empty();
```

#### `length()和size()`

- 返回字符串中的字符数

> 示例

```c++
std::string str{"abc"};
str.length();
str.size();
```

#### `[]和at()`

- 访问特定索引处的字符

> 示例

```c++
std::string str{"abcd"};
str[2];
str.at(2);
```

#### `insert()`

- 可以通过`insert()`函数将字符插入到现有字符串中。

```c++
string& string::insert (size_type index, const string& str)
string& string::insert (size_type index, const char* str)
```

- 参数

  - `index`:要添加元素下标位置
  - `str`:添加字符串

  > 示例

  ```c++
  std::string str{"abcd"};
  str.insert(2, "cd");
  ```

#### `+=, append(), push_back()`

- 使用操作符`+=`、`append()`或`push_back()`函数可以很容易地将字符串追加到现有字符串的末尾。

```c++
string& string::operator+= (const string& str)
string& string::append (const string& str)
void string::push_back (char c)
```

> 示例

```c++
std::string str{"one"};
str += "two";
str.append("three");
str.push_back('a');
```

#### `swap()`

- 将内容与 `other` 的交换。不在单个元素上调用任何移动、复制或交换操作。

```c++
void swap(vector& other);
```

- 参数

  - `other`:要与之交换内容的容器
  
  > 示例
  
  ```c++
  std::string str1{"abc"};
  std::string str2{"def"};
  str1.swap(str2);
  ```

#### `c_str()和data()`

- 返回指向拥有数据等价于存储于字符串中的空终止字符数组的指针

```c++
const char* c_str() const;
const char* string::data () const
```

> 示例

```c++
std::string str{"abc"};
str.c_str();
```

## `std::array`

- `std::array`提供固定的数组功能，传递给函数时不会衰减。 `std::array`在`std`名称空间内的<array>标头中定义。

```c++
#include <array>
std::array<int, 3> arr;
```

- `std::array` 可以使用初始化列表或列表初始化进行初始化：

```c++
std::array<int, 3> arr1 = {1, 2, 3};
std::array<int, 3> arr2{4, 5, 6};
```

- 与内置固定数组不同，使用`std :: array`时，您不能在提供初始化程序时忽略数组长度

- 从C ++ 17开始，允许省略类型和大小。仅在显式初始化数组的情况下，只能一起省略它们，而不能一个或另一个。

```c++
std::array arr{1, 2, 3};
```

- `std::array`使用下标运算符访问值

```c++
std::array<int, 2> arr{1, 2};
std::cout << arr[1];
```

### 大小和排序

- 该`size()`函数可用于检索的长度`std::array`：

```c++
std::array<int, 3> arr{1, 2, 3}
std::cout << arr.size();
```

- 由于长度始终是已知的，因此基于范围的for循环可用于`std::array`：

```c++
std::array<int, 2> arr{1, 3};
for (auto i : arr)
    std::cout << i << ' ';
```

- `std::array`使用排序`std::sort`，它位于<algorithm>标头中：

```c++
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> myarr{3, 2, 4, 1};
    std::sort(myarr.begin(), myarr.end());
    for(auto elem : myarr)
        std::cout << elem << ' ';
    
    return 0;
}    
```
