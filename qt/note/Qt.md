# `Qt`创建模板解释
- 在`Qt`的`Widgets`应用程序向导创建一个包含主源文件和一组文件中指定的用户界面（记事本窗口小部件）项目：
notepad.pro-项目文件。
    > `yourName.pro`:项目文；
    > `main.cpp`:应用程序的主要源文；
    > `yourName.cpp`:你创建的项目文件的源文；
    > `yourName.h`:你创建的项目文件的头文；
    > `yourName.ui`:UI窗口。
- QWidget、QMainWindow和QDialog之间的关系：
**`QWidget` -> `QMainWindow`**
**`QWidget` -> `QDialog`**
## 主函数
> main.cpp
```c++
#include "mywidget.h"

#include <QApplication> // 包含应用程序类的头文件

int main(int argc, char *argv[])
{
    // a为应用程序对象，在`Qt`中，有且只有一个
    QApplication a(argc, argv);
    myWidget w;
    
    // 窗口对象，默认不会显示，需要调用show函数
    w.show();
    
    // 应用程序对象进入消息循环，代码将会阻塞在这（不是循环）
    return a.exec();
}

```

> .pro
```c++
#Qt包含的模块
QT       += core gui

#大于4版本以上，就加上widgets模板
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#源文件
SOURCES += \
    main.cpp \
    mywidget.cpp

#头文件
HEADERS += \
    mywidget.h

TRANSLATIONS += \
    01_myFirst_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
```

> yourName.h
```c++
#ifndef MYWIDGET_H
#define MYWIDGET_H

// 包含头文件QWidget类
#include <QWidget>

class myWidget : public QWidget
{
    // Q_OBJECT宏，允许类中信号和槽机制
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};
#endif // MYWIDGET_H
```
