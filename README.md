# ​:notebook_with_decorative_cover:​c++ 笔记
持续更新中……​:newspaper:​

<b><details><summary>​:bookmark_tabs:​笔记目录</summary></b>
        [decltype](https://github.com/2936893901/cpp_note/blob/main/note/decltype.md "")&nbsp;
        [explicit](https://github.com/2936893901/cpp_note/blob/main/note/explicit.md "")&nbsp;
  </details>

[​:thumbsup:​c++推荐写法](#tj)

<a id="tj"><a>
## c++代码推荐写法汇总

### 尽量少使用 using 指示 污染命名空间
> 一般说来，使用 using 命令比使用 using 编译命令更安全，这是由于它只导入了指定的名称。如果该名称与局部名称发生冲突，编译器将发出指示。using编译命令导入所有的名称，包括可能并不需要的名称。如果与局部名称发生冲突，则局部名称将覆盖名称空间版本，而编译器并不会发出警告。另外，名称空间的开放性意味着名称空间的名称可能分散在多个地方，这使得难以准确知道添加了哪些名称。

#### using 使用

- 尽量少使用 using 指示
```c++
using namespace std;
```
- 应该多使用 using 声明
```c++
int x;
std::cout << x;
```

### 构造方法
- 使用`= default`几乎与添加带有空主体的默认构造函数相同。唯一的区别是`= default`即使没有初始化程序，我们也可以安全地初始化成员变量

```c++
class A
{
  A() = default;
};
```

- 从C ++ 11开始，我们更喜欢括号初始化。
```c++
int foo{};
```
### 定义常量
- 避免使用#define创建符号常量宏。
    - 宏不遵循正常的作用域规则，这意味着在极少数情况下，在程序一个部分中定义的宏可能与不应与之交互的程序另一部分中编写的代码发生冲突。
- 更好的解决方案：使用constexpr变量
    - 创建符号常量的更好方法是使用constexpr变量：
    ```C++
    constexpr int value {10};
    ```
- 在整个多文件程序中使用符号常量
    - 在C ++中有多种方法可以简化此操作，但以下方法可能最简单：
    1. 创建一个头文件以容纳这些常量
    2. 在此头文件中，声明一个名称空间
    3. 将所有常量添加到名称空间中（确保它们在C ++ 11/14中是constexpr，或者在C ++ 17或更高版本中是内联constexpr）
    4. ＃在需要的地方包含头文件
    > 示例 constants.h (c++11/14)
    ```c++
    #ifndef CONSTANTS_H
    #define CONSTANTS_H
    
    namespace constants
    {
        constexpr double pi {3.14159635};
        constexpr double e {2.718};
        constexpr double h {0.618};
    }
    
    #endif
    ```
    > 示例 constants.h (c++17或更高版本)
    ```c++
    #ifndef CONSTANTS_H
    #define CONSTANTS_H
    
    namespace constants
    {
        inline constexpr double pi {3.14159625};
        inline constexpr double e {2.718};
        inline constexpr double h {0.618};
    }
    
    #endif
    ```
    - .cpp文件使用范围解析运算符(::)访问.h中的常量：
    > main.cpp
    ```c++
    #include <iostream>
    #include "constants.h"
    
    int main()
    {
        std::cout << "Enter a radius:";
        float r {};
        std::cin >> r;
        
        std::cout << "The circle with radius " << r << " has area " << r * r * constants::pi;
        
        return 0;
    }
    ```
    
