#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

// 声明全局常数
const int MAX = 5;

template<typename T>
class Array
{
	T array[MAX];
public:
	Array()
	{
		for (int i{0}; i < MAX; ++i)
			array[i] = 0;
	}
	// 重载[]
	T &operator[](int index);
	// 排列
	void Sort();
};

template<typename T>
T &Array<T>::operator[](int index)
{
	assert(index >= 0 && index < MAX);
	return array[index];
}

template<typename T>
void Array<T>::Sort(){
    for(int i{0}; i < MAX-1; i++){
	    int p{i}, j;
        for(j = i+1; j < MAX; j++){
            if(array[p] < array[j])
                p = j;
        }
        T t {array[i]};
        array[i] = array[p];
        array[p] = t;
    }   
}

template<>
void Array<char *>::Sort()
{
	for (int i{0}; i < MAX - 1; ++i)
	{
		int p{i}, j;
		for (j = i+1; j < MAX; ++j)
			if (strcmp(array[p], array[j]) < 0)
				p = j;
		char *t {array[i]};
		if (t != NULL)
		{
			array[i] = array[p];
			array[p] = t;
		}

		delete t;
	}
}

int main()
{
	Array<int> a1;
	Array<char *> a2;

	std::cout << "\n-----1. current-----\n";
	for (int i{0}; i < MAX; ++i)
	{
		int randnum = std::rand() % 100 + 1;
		a1[i] = randnum;
		std::cout << a1[i] << ' ';
	}

	std::cout << "\n-----1. result-----\n";
	a1.Sort();
	for (int j{0}; j < MAX; ++j)
		std::cout << a1[j] << ' ';

	std::cout << "\n-----2. result-----\n";
	const char *str[] = {"I", "want", "to", "wc", "now"};
	for (int i{0}; i < MAX; ++i)
		a2[i] = const_cast<char *> (str[i]);	// 将str的值带入数组中，强制转换为char*类型

	a2.Sort();
	for (int j{0}; j < MAX; ++j)
		std::cout << a2[j] << ' ';
	
	return 0;
}
