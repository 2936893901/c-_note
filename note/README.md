<a id="top"></a>
# [:notebook_with_decorative_cover:<font color=#000>c++ 笔记</font>](../README.md)
持续更新中……:newspaper:
<b><details><summary>:bookmark_tabs:笔记目录(乱序)</summary></b>
            [decltype](decltype.md)  
            [explicit](explicit.md)  
            [STL容器](STL%E5%AE%B9%E5%99%A8.md)  
            [extern](extern.md)  
            [位域](%E4%BD%8D%E5%9F%9F.md)  
            [信号处理](%E4%BF%A1%E5%8F%B7%E5%A4%84%E7%90%86.md)  
            [其他数据类型](%E5%85%B6%E4%BB%96%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B.md)  
            [函数](%E5%87%BD%E6%95%B0.md)  
            [动态记忆](%E5%8A%A8%E6%80%81%E8%AE%B0%E5%BF%86.md)  
            [双冒号](%E5%8F%8C%E5%86%92%E5%8F%B7.md)  
            [名称可见性](%E5%90%8D%E7%A7%B0%E5%8F%AF%E8%A7%81%E6%80%A7.md)  
            [基本输入输出](%E5%9F%BA%E6%9C%AC%E8%BE%93%E5%85%A5%E8%BE%93%E5%87%BA.md)  
            [多线程](%E5%A4%9A%E7%BA%BF%E7%A8%8B.md)  
            [字符序列](%E5%AD%97%E7%AC%A6%E5%BA%8F%E5%88%97.md)  
            [存储类](%E5%AD%98%E5%82%A8%E7%B1%BB.md)  
            [异常处理](%E5%BC%82%E5%B8%B8%E5%A4%84%E7%90%86.md)  
            [引用与指针](%E5%BC%95%E7%94%A8%E5%92%8C%E6%8C%87%E9%92%88.md)  
            [指针](%E6%8C%87%E9%92%88.md)  
            [数据结构](%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84.md)  
            [数组](%E6%95%B0%E7%BB%84.md)  
            [文件和流](%E6%96%87%E4%BB%B6%E5%92%8C%E6%B5%81.md)  
            [模板](%E6%A8%A1%E6%9D%BF.md)  
            [类](%E7%B1%BB.md)  
            [语句和流程控制](%E8%AF%AD%E5%8F%A5%E5%92%8C%E6%B5%81%E7%A8%8B%E6%8E%A7%E5%88%B6.md)  
            [运算](%E8%BF%90%E7%AE%97.md)  
            [重载和模板](%E9%87%8D%E8%BD%BD%E5%92%8C%E6%A8%A1%E6%9D%BF.md)  
            [预处理器](%E9%A2%84%E5%A4%84%E7%90%86%E5%99%A8.md)  
            [STL迭代器](STL%E8%BF%AD%E4%BB%A3%E5%99%A8.md)  
            [lambda](Lambda.md)  
            [设计模式](Design%20Patterns.md)  
            [R值引用](R%E5%80%BC%E5%BC%95%E7%94%A8.md)  
            [移动构造函数和移动分配](%E7%A7%BB%E5%8A%A8%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0%E5%92%8C%E7%A7%BB%E5%8A%A8%E5%88%86%E9%85%8D.md)  
            [move](move.md)  
            [STL](STL.md)  
  </details>

[:thumbsup:c++推荐写法](#tj)

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
std::cout << "Hello World";
```

### 构造方法
- 使用`= default;`几乎与添加带有空主体的默认构造函数相同。唯一的区别是`= default;`即使没有初始化程序，我们也可以安全地初始化成员变量

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
### auto关键字
- 初始化变量的类型推断
- 虽然使用auto代替基本数据类型只节省了很少的击键次数(如果有的话)，但是在以后，我们将看到一些类型变得复杂和冗长的示例。在这些情况下，使用auto可以节省大量输入。
- 避免对函数返回类型使用类型推断。
```c++
auto sum {1 + 2 + 3};
```

### const 和 constexpr的区别
- const用于运行期常量，constexpr用于编译期常量
- constexpr 是 C++11 引入的，一方面是为了引入更多的编译时计算能力，另一方面也是解决 C++98 的 const 的双重语义问题。在 C 里面，const 很明确只有「只读」一个语义，不会混淆。C++ 在此基础上增加了「常量」语义，也由 const 关键字来承担，引出来一些奇怪的问题。C++11 把「常量」语义拆出来，交给新引入的 constexpr 关键字。
- 在 C++11 以后，建议凡是「常量」语义的场景都使用 constexpr，只对「只读」语义使用 const。

### nullptr
`nullptr`出现的目的是为了替代`NULL`。在某种意义上来说，传统`C++`会把`NULL`、0视为同一种东西，这取决于编译器如何定义 `NULL`，有些编译器会将`NULL`定义为`((void*)0)`，有些则会直接将其定义为0。  

> g++ main.cpp
```c++
#include <iostream>

void func(int)
{
    std::cout << "func(int) is called" << std::endl;
}
    
void func(char *)
{
    std::cout << "func(char *) is called" << std::endl;
}
    
int main()
{
    func(0);
    // func(NULL);  // 该行不能通过编译
    func(nullptr);
    return 0;
}
```

> 輸出
```
func(int) is called
func(char *) is called
```

* **`NULL`不同于0与`nullptr`。所以，请养成直接使用`nullptr`的习惯。**

## 被棄用
* 不再允许字符串字面值常量赋值给一个`char *`。如果需要用字符串字面值常量赋值和初始化一个`char *`，应该使用`const char *`或者`auto`。
```c++
char *str = "Warning"; // 将出现弃用警告
```
* `bool`类型的`++`操作被弃用。
* `std::auto_ptr`被弃用，应使用`std::unique_ptr`。
* `C++98`异常说明、`unexpected_handler`、`set_unexpected()`等相关特性被弃用，应该使用 `noexcept`。
* `C`语言风格的类型转换被弃用（即在变量前使用`convert_type`），应该使用`static_cast`、`reinterpret_cast`、`const_cast`来进行类型转换。
* 特别地，在最新的`C++17`标准中弃用了一些可以使用的`C`标准库，例如`<ccomplex>`、`<cstdalign>`、`<cstdbool>`与`<ctgmath>`等
* .....

## 致謝
* [Modern C++ Tutorial](https://github.com/changkun/modern-cpp-tutorial)

[<p align="center">​:top:​</p>](#top)
