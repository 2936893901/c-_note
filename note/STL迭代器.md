# STL迭代器

- 一个迭代器是一个对象，可以遍历（迭代以上），而不必知道该容器是如何实现用户的容器类。对于许多类（尤其是列表和关联类），迭代器是访问这些类元素的主要方式。

- 最好将迭代器可视化为指向容器中给定元素的指针，并使用一组重载运算符来提供一组定义明确的函数：
  - `operator*`-取消引用迭代器将返回迭代器当前指向的元素。
  - `operator ++` -将迭代器移动到容器中的下一个元素。大多数迭代器还提供`Operator--`移至上一个元素的功能。
  - `operator==和operator!=` -基本比较运算符，用于确定两个迭代器是否指向同一元素。若要比较两个迭代器指向的值，请先取消引用迭代器，然后使用比较运算符。
  - `operator =` -将迭代器分配到新位置（通常是容器元素的开始或结束）。要分配迭代器所指向的元素的值，请先取消引用迭代器，然后使用`assign`运算符。

- 每个容器包括四个基本成员函数，可与运算符=一起使用：
  - `begin（）`返回一个迭代器，该迭代器表示容器中元素的开始。
  - `end（）`**返回代表该元素刚刚结束的元素的迭代器**【end（）并不指向列表中的最后一个元素】。
  - `cbegin（）`返回一个`const`（只读）迭代器，该迭代器表示容器中元素的开头。
  - `cend（）`返回一个`const`（只读）迭代器，该迭代器表示刚刚超出元素末尾的元素。

- 容器都提供（至少）两种迭代器：
  - `container :: iterator`提供读/写迭代器
  - `container :: const_iterator`提供一个只读的迭代器

----

## 示例

### 遍历向量

```c++
#include <iostream>
#include <vector>

int main()
{
    // 声明一个int向量
    std::vector<int> vet;
    
    // 遍历向量
    for(int i {0}; i < 6; ++i)
        vet.push_back(i);
    
    // 声明一个迭代器
    std::vector<int>::iterator it;
    
    // 将迭代器分配到向量的起始点
    it = vet.begin();
    for(it; it != vet.end(); ++it)
        std::cout << *it << " ";
    return 0;
}
```



### 遍历列表

```c++
#include <iostream>
#include <list>

int main()
{
    std::list<int> ls;
    for(int i {0}; i < 6; ++i)
        ls.push_back(i);
    std::list<int>::iterator it;
    it = ls.begin();
	while(it != ls.end())
    {
     	std::cout << *it << " ";
        ++it;
    }
    return 0;
}
```



### 遍历集合

```c++
#include <iostream>
#include <set>

int main()
{
    std::set<int> s;
    s.insert(2);
    s.insert(6);
    s.insert(-1);
    s.insert(9);
    s.insert(3);
    s.insert(7);
    
    std::set<int>::iterator it;
    it = s.begin();
    while(it != s.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    return 0;
}
```



### 遍历地图

```c++
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string str[] = {"red", "yellow", "blue", "green", "black", "white"};
    std::map<int, std::string> m;
    for(int i {0}; i < 6; ++i)
        m.insert(std::make_pair(i, str[i]));
    auto it {m.begin()};
    while(it != m.end())
    {
        std::cout << it->first << ":" << it->second << " ";
        ++it;
    }
    return 0;
}
```

