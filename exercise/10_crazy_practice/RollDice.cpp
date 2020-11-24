#include <iostream>
#include <stdlib.h>
#include <exception>
using namespace std;

// 定义全局变量
int a = 0;

// 生成随机数
int dice()
{
	int num1 = rand() % 6 + 1;
	int num2 = rand() % 6 + 1;
	return num1 + num2;
}

// 随机点数与得分
void randDice(int value)
{
	srand(rand() % 10 + 1);
	switch(value)
	{
	case 1:
		++a;
		cout << "You took a step and get a flag" << endl;
		break;
	case 4:
		++a;
		cout << "You took four step and get a flag" << endl;
		break;
	case 5:
		--a;
		cout << "You took five step and lost a flag" << endl;
		break;
	case 8:
		--a;
		cout << "You took eight step and lost a flag" << endl;
		break;
	case 10:
		a -= 2;
		cout << "You took ten step and lost two flag" << endl;
		break;
	case 11:
		++a;
		cout << "You took eleven step and get a flag" << endl;
		break;
	case 2:case 3:case 6:case 7:case 9:case 12:
		cout << "Nothing at all" << endl;
	default:
		a = 0;
		break;
	}
}

// 循环掷骰子
void whilegame(int time, char can)
{
	while(--time)
	{
		// 判断玩家是否需要进行下一步
		if (can == 'y' || can == 'Y')
		{
			randDice(dice());
		}
		else if(can == 'n' || can == 'N') break;
		else break;
	}
}

// 输出信息总分
void printmsg(int value)
{
	cout << "Game Over!" << endl;
	cout << "You have " << value << " flag" << endl;
	string str = (value > 0) ? "You win!" : "You lost";
	cout << str << endl;
	a = 0;
}

int main(int argc, char const *argv[])
{
	int& flag = a;
	int time = 10;
	char can;
	bool again;

	cout << "Game Start!" << endl;

	do{
		cout << "Can we get started?[y/n]:";
		cin >> can;
		whilegame(time, can);

		printmsg(flag);

		cout << "Would you like to do it again?[y/n]:";
		again = (can == 'y' || can == 'Y') ? true : false;
	}while(again);

	return 0;
}