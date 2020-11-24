#ifndef RESOURCES_H
#define RESOURCES_H

// 书类
class Book
{
	Book* b_p;
public:
	Book(Book* p = nullptr):b_p(p)
	{
		p = new Book;
		std::cout << "Book()";
	}
	~Book()
	{
		delete b_p;
		std::cout << "~Book()";
	}
};

#endif