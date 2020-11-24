#include <iostream>
#include <mutex>

enum class Shape_type
{
	circle,
	triangle,
	rectangle
};

class shape
{
public:
	shape(){std::cout << "shape\n";}
	virtual ~shape(){}
	virtual void print(){std::cout << "I am a shape\n";}
};

class circle : public shape
{
public:
	circle(){std::cout << "circle\n";}
	void print(){std::cout << "I am a circle\n";}
};

class triangle : public shape
{
public:
	triangle(){std::cout << "triangle\n";}
	void print(){std::cout << "I am a rectangle\n";}
};

class rectangle : public shape
{
public:
	rectangle(){std::cout << "rectangle\n";}
	void print(){std::cout << "I am a rectangle\n";}
};

shape* create_shape(Shape_type type)
{
	switch(type)
	{
		case Shape_type::circle:
			return new circle();
			break;
		case Shape_type::triangle:
			return new triangle();
			break;
		case Shape_type::rectangle:
			return new rectangle();
			break;
	}
}

class shape_wrapper
{
	shape *s_ptr;
public:
	shape_wrapper(shape *p = nullptr) : s_ptr{p}{}
	~shape_wrapper(){delete s_ptr;}
	shape* getptr() const {return s_ptr;}
};

void foo(Shape_type type)
{
	shape_wrapper ptr(create_shape(type));
	ptr.getptr()->print();
}

int main(int argc, char const *argv[])
{
	shape* s = create_shape(Shape_type::triangle);
	s->print();

	foo(Shape_type::circle);
	
	return 0;
}
