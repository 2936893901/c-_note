#include <iostream>

// 模拟栈结构
template<typename T, int maxSize>
class Stack
{
	T elem[maxSize];
	int top;
public:
	Stack(){top = 0;}

	// 将栈清空
	void setEmpty()
	{
		top = -1;
	}

	// 压栈
	void push(T e);

	// 出栈
	T pop();

	// 判断栈中是否为空
	bool empty()
	{
		return (top <= -1) ? 1 : 0;
	}

	// 判断栈是否已满
	bool full()
	{
		return (top >= maxSize - 1) ? 1 : 0;
	}

};

template<typename T, int maxSize>
void Stack<T, maxSize>::push(T e)
{
	if (full())
		std::cout << "栈已满" << std::endl;
	else
		elem[++top] = e;
}

template<typename T, int maxSize>
T Stack<T, maxSize>::pop()
{
	if(empty())
	{
		std::cout << "栈已空" << std::endl;
		return 0;
	}
	else
		return elem[--top];
}


// 模拟数组
template<typename T, int s>
class Array
{
	T arr[s];
public:
	Array(){
		for (int i = 0; i < s; ++i)
			arr[i] = 0;
	}
	T &operator[](int x);
	void Sort();
};

template<typename T, int s>
T &Array<T, s>::operator[](int x)
{
	if (x < 0 || x > s - 1)
	{
		std::cout << "Array index is out of bounds...\n";
		exit(1);
	}
	return arr[x];
}

// template<typename T, int s>
// void Array<T, s>::Sort()
// {
// 	for (int i = 0; i < s - 1; ++i)
// 	{
// 		int l = i;
// 		for (int j = i; j < s; ++j)
// 		{
// 			if (arr[l] < arr[j])
// 				l = j;
// 		}

// 		T t1 = arr[l];
// 		t1[l] = arr[i];
// 		arr[i] = t1;
// 	}
// }

// template <> 返回类型 类模板名<特化的数据类型>::特化成员函数名(参数表){}
// template<>
// void Array<char *>::Sort()
// {

// }

int main(int argc, char const *argv[])
{
	std::cout << "\n-----Stack-----\n";
	Stack<int, 10> s;
	s.setEmpty();
	for (int i = 0; i < 10; ++i)
	{
		s.push(i);
		// std::cout << s.pop();
	}
	s.push(11);

	std::cout << "\n-----Sort-----\n";
	Array<char, 5> a;

	return 0;
}
