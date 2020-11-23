# 设计模式

## 单例模式

### 懒汉式单例模式

```c++
class Singleton
{
private:
	Singleton() {};
	static Singleton *pInstance;
public:
	static Singleton *getSingleton()
	{
		if (pInstance == nullptr)
			pInstance = new Singleton();
		return pInstance;
	}
};
```

### 线程安全单例模式

```c++
class Singleton
{
private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton &);
	Singleton &operator=(const Singleton &);
public:
	static Singleton &getSingleton()
	{
		static Singleton instance;
		return instance;
	}
};

```

