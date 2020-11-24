#include <iostream>
#include "Resources.h"

// auto_ptr的核心实现:
template<typename T>
class auto_p
{
	T* ptr;
public:
	auto_p(T* _ptr = nullptr):ptr(_ptr){}
	~auto_p(){delete ptr;}

	T* get() noexcept {return ptr;}

	// 使该类对象的行为像指针，重载三种指针的基本操作
	T& operator*() const noexcept {return *ptr;}
	T* operator->() const noexcept {return ptr;}
	operator bool() const noexcept {return ptr;}

	// 释放原来指针所有权
	T* release() noexcept
	{
		T* p = ptr;
		ptr = nullptr;
		return p;
	}

	// 转换指针所有权
	void swap(auto_p& p) noexcept
	{
		using std::swap;
		swap(ptr, p.ptr);
	}

	// 拷贝构造,被复制方释放原来指针的所有权,交给复制方
	auto_p(auto_p& other) noexcept
	{
		ptr = other.release();
	}

	// 复制和转移
	auto_p& operator=(auto_p& other) noexcept
	{
		auto_p(other.release()).swap(*this);
		return *this;
	}

};

template<typename T>
void swap(auto_p<T>& first, auto_p<T>& second) noexcept
{
	first.swap(second);
}

int main(void)
{
	auto_p<Book> p1{new Book};
	auto_p<Book> p2{p1};	// 复制p1初始化

	if (p1.get())
		std::cout << "sss";

	// if (p1.get() == nullptr && p2.get())
	// {
	// 	std::cout << "copy: p1 release of ownership, and p2 take possession of\n";
	// }
	p1 = p1;

	return 0;
}