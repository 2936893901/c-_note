#include <iostream>

template<typename T, int MAX>
class Stack
{
    T elem[MAX];
    int top{};
public:
    Stack():top(-1){}
    
    // 返回栈是否为空
    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    
    // 返回栈是否已满
    bool full()
    {
        if (top >= MAX)
            return true;
        else
            return false;
    }
    
    // 出栈
    T pop();
    
    // 压栈
    void push(T t);
};

template<typename T, int MAX>
T Stack<T, MAX>::pop()
{
    if (!empty())
        return elem[--top];
    else
    {
        std::cout << "栈已空\n";
        return 0;
    }
}

template<typename T, int MAX>
void Stack<T, MAX>::push(T t)
{
    if (!full())
        elem[++top] = t;
    else
        std::cout << "栈已满\n";
}

int main()
{
    Stack<int, 5> s;

	for (int i{0}; i <= 6; ++i)
		s.push(i);
	for (int j{0}; j <= 6; ++j)	
		s.pop();
    
    return 0;
}
