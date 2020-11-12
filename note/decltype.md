# `decltype`

## 1. 基本使用

- 语法

```c++
decltype (experession)
```

- 这里的括号是必不可少的,`decltype`的作用是“查询表达式的类型”，因此，上面语句的效果是，返回 expression 表达式的类型。注意，`decltype `仅仅“查询”表达式的类型，并不会对表达式进行“求值”。

****

### 1.1 推导出表达式类型

```c++
int i = 1;
decltype(i) a; //推导结果为int,a的类型为int.
```

****

### 1.2 与`using/typedef`合用，用于定义类型

```c++
using size_t = decltype(sizeof(0));
using nullptr_t = decltype(nullptr);
```

****

### 1.3 重用匿名函数

```c++
struct
{
    int i;
    double d;
}annon_s;
```

- 借助`decltype`，可以重新使用这个匿名结构体

```c++
decltype (annon_s) as;
```

****

### 1.4 泛型编程中结合auto，用于追踪函数的返回值类型

- 这也是`decltype`最大的用途



#### 示例

```c++
#include <iostream>
#include <vector>
using namespace std;

template <class T>
auto mult(T x, T y)->decltype(x*y)
{
    return x*y;
}

int main()
{
    cout << mult(11,22) << end1;
    return 0;
}
```



## 2. 判别规则

- 对于`decltype(e)`而言，其判别结果受以下条件的影响：

  - 如果e是一个**没有带括号的标记符表达式或者类成员访问表达式**，那么的`decltype(e)`就是e所命名的实体的类型。

  - 如果e是一个**被重载的函数**，则会导致编译错误**。**
  - 假设e的类型是T，如果**e是一个将亡值**，那么`decltype（e）`为T&&
  - 假设e的类型是T，如果**e是一个左值**，那么`decltype(e)`为T&。 
  - 假设e的类型是T，则`decltype(e)`为T。