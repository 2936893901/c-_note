#include <iostream>
#include "Resources.h"

template<typename T>
class scoped_p
{
	T* ptr;
	scoped_p(scoped_p const&);
	scoped_p& operator=(scoped_p const&);
public:
	scoped_p(T* p = 0) : ptr(p) {}
	~scoped_p(){delete ptr;}

	void reset(T* p)
	{
		scoped_p(p).swap(*this);
	}

	void swap(T& p)
	{
		using std::swap;
		swap(ptr, p.ptr);
	}

	T& operator*(){return *ptr;}
	T* operator->(){return ptr;}
	T* get() const {return ptr;}
};

template<typename T>
void swap(scoped_p<T>& t1, scoped_p<T>& t2)
{
	t1.swap(t2);
}

int main(void)
{
	scoped_p<Test> p1{new Test};
// 	scoped_p<Test> p2{p1}	// error: declared private,no copy
	return 0;
}
