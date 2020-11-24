# 智能指针

### [auto_ptr](Auto_ptr.cpp)
----
### [scoped_ptr](Scoped_ptr.cpp)
scoped_ptr特点总结：
1. 与auto_ptr类似，采用栈上的指针去管理堆上的内容，从而使得堆上的对象随着栈上对象销毁时自动删除；
2. scoped_ptr有着更严格的使用限制——不能拷贝，这也意味着scoped_ptr不能转换其所有权，所以它管理的对象不能作为函数的返回值，对象生命周期仅仅局限于一定区间（该指针所在的{}区间，而std::auto_ptr可以）；
3. 由于防拷贝的特性，使其管理的对象不能共享所有权，这与std::auto_ptr类似，这一特点使该指针简单易用，但也造成了功能的薄弱。
----
### [unique_ptr](Unique_ptr.cpp)
----
