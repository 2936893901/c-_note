# `Qt`信号与槽机制

## 信号与槽（Signal & Slot）

- 信号与槽（`Signal & Slot`）是`Qt`编程的基础，也是`Qt`的一大创新。因为有了信号与槽的编程机制，在`Qt`中处理界面各个组件的交互操作时变得更加直观和简单。

- 信号（`Signal`）就是在特定情况下被发射的事件，例如`PushButton` 最常见的信号就是鼠标单击时发射的 `clicked()` 信号，一个 `ComboBox` 最常见的信号是选择的列表项变化时发射的 `CurrentIndexChanged() `信号。

- 槽（`Slot`）就是对信号响应的函数。槽就是一个函数，与一般的[C++](http://c.biancheng.net/cplus/)函数是一样的，可以定义在类的任何部分（`public`、`private` 或 `protected`），可以具有任何参数，也可以被直接调用。槽函数与一般的函数不同的是：槽函数可以与一个信号关联，当信号被发射时，关联的槽函数被自动执行。

- 信号与槽关联是用 `QObject::connect()` 函数实现的，其基本格式是：

```c++
QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
```

- `connect()` 是 `QObject` 类的一个静态函数，而 `QObject` 是所有 `Qt` 类的基类，在实际调用时可以忽略前面的限定符，所以可以直接写为：

```c++
connect(sender, STNAL(signal()), receiver, SLOT(slot()));
```
- 参数
  - `sender `是发射信号的对象的名称
  - `signal() `是信号名称。信号可以看做是特殊的函数，需要带括号，有参数时还需要指明参数
  - `receiver` 是接收信号的对象名称
  - `slot() `是槽函数的名称，需要带括号，有参数时还需要指明参数。

**在使用信号与槽的类中，必须在类的定义中加入宏 Q_OBJECT。**

- QT 信号槽connect三种写法
```c++
 QPushButton *btn = new QPushButton;

    // 方式一：老式写法
    connect(btn, SIGNAL(clicked()), this, SLOT(close()));

    // 方式二：Qt5后新写法
    connect(btn, &QPushButton::clicked, this, &MainWindow::close);

    // 方式三：lambda表达式
    connect(btn, &QPushButton::clicked, this, [&]() {
        this->close();
    });
```
- 方式一 老式写法，在编译的时候即使信号或槽不存在也不会报错，但是在执行的时候无效，对于C++这种静态语言来说，这是不友好的，不利于调试；

- 方式二 Qt5后推荐的写法，如果编译的时候信号或槽不存在是无法编译通过的，相当于编译时检查，不容易出错，还有就是槽的写法可以直接写在public控制域下，不一定非要写在public slots:控制域下；

- 方式三 采用了lambda表达式的写法，更加方便快捷。
