# extern

## 1. C++与C编译区别

- 在C++中常在头文件见到extern "C"修饰函数，是用于C++链接在C语言模块中定义的函数。

- C++虽然兼容C，但C++文件中函数编译后生成的符号与C语言生成的不同。因为C++支持函数重载，C++函数编译后生成的符号带有函数参数类型的信息，而C则没有。

## 2. C++调用C函数

- C++调用C函数的例子: 引用C的头文件时，需要加`extern "C"`



- `add.h`

```c
#ifndef ADD_H
#define ADD_H
extern int add(int x, int y);
#endif
```



- `add.c`

```c
#include "add.h"

int add(int x, int y)
{
    return x + y;
}
```



- `add.cpp`

```c++
#include <iostream>
using namespace std;
extern "C"{
    #include "add.h"
}
int main()
{
    add(1, 2);
    return 0;
}
```



- 编译顺序

  1. ```c++
     gcc -c add.c
     ```

  2. ```c++
     g++ add.cpp add.o
     ```



## 3. C中调用C++函数

- `extern "C"`在C中是语法错误，需要放在C++头文件中。



```c++
// add.h
#ifndef ADD_H
#define ADD_H
extern "C"{
    int add(int x, int y);
}
#endif

// add.cpp
#include "add.h"

int add(int x, int y)
{
    return x + y;
}

// add.c
extern int add(int x, int y);
int main()
{
    add(1, 2);
    return 0;
}
```



- 编译顺序

  1. ```c++
     g++ -c add.cpp
     ```

  2. ```c++
     gcc add.c add.o
     ```