# `Qt`创建模板解释
- 在`Qt`的`Widgets`应用程序向导创建一个包含主源文件和一组文件中指定的用户界面（记事本窗口小部件）项目：
notepad.pro-项目文件。
    > `yourName.pro`:项目文件
    > `main.cpp`:应用程序的主要源文件
    > `yourName.cpp`:你创建的项目文件的源文件
    > `yourName.h`:你创建的项目文件的头文件
    > `yourName.ui`:UI窗口
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
