# `MainWindow`
## `QMenubar`
1. 创建菜单栏
```c++
QMenuBar *bar = menuBar();
```
2. 将菜单栏放入窗口
```c++
setMenuBar(bar);
```
3. 创建菜单
```c++
QMenu *firstMenu = bar->addMenu("first");
```
4. 创建菜单项
```c++
firstMenu->addAction("one");
// 添加分隔符
firstMenu->addSeparator();
```
