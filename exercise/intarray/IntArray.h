#ifndef INTARRAY_H
#define INTARRAY_H

#include <assert.h>

class IntArray
{
private:
	int length{};
	int *data{};
public:
	// 默认的构造方法
	IntArray() = default;
	IntArray(int len) : length{len}
	{
		assert(len >= 0);
		if (len > 0)
			data = new int[len]{};
	}
	~IntArray(){delete[] data;}

	// 清除数据
	void eraser()
	{
		delete[] data;
		data = nullptr;
		length = 0;
	}

	// 重载[]运算符
	int &operator[](int index)
	{
		assert(index >= 0 && index < length);
		return data[index];
	}

	// 获得数组长度
	int getLength() const {return length;}

	// 重新分配数组长度
	void reallocate(int new_len)
	{
		eraser();
		if (new_len <= 0)
			return;
		data = new int[new_len];
		length = new_len;
	}

	// 调整数组大小
	void resize(int new_len)
	{
		// 判断输入长度是否等于当前长度
		if (new_len == length)
			return;

		// 长度小于等于零相当于清除数组
		if (new_len <= 0)
		{
			eraser();
			return;
		}
		int *d {new int[new_len]};

		// 输入长度大于零则替换原本大小的数组长度
		if (new_len > 0)
		{
			int elem {(new_len > length) ? new_len : length};
			for (int i{0}; i < elem; ++i)
				d[i] = data[i];
		}

		delete[] data;

		data = d;
		length = new_len;
	}

	// 插入数据
	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index < length);
		int *d{new int[length + 1]};

		for (int before{0}; before < index; ++before)
			d[before] = data[before];
		d[index] = value;
		for (int after{index}; after < length; ++after)
			d[after + 1] = data[after];
		delete[] data;

		data = d;
		++length;
	}

	// 移除指定下标的元素
	void remove(int index)
	{
		assert(index >= 0 && index < length);
		if (index == length)
		{
			eraser();
			return;
		}
		int *d{new int[length - 1]};
		for (int f{0}; f < index; ++f)
			d[f] = data[f];
		for (int elem{index + 1}; elem < length; ++elem)
			d[elem - 1] = data[elem];

		delete[] data;

		data = d;
		--length;
	}

	void insertBegin(int value){insertBefore(value, 0);}
	void insertEnd(int value){insertBefore(value, length);}
};

#endif