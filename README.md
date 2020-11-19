# ​:notebook_with_decorative_cover:​c++ 笔记

- <details><summary>​:bookmark_tabs:​笔记目录</summary>
  1. []()
  </details>

- [​:thumbsup:​c++推荐写法](#tj)

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
