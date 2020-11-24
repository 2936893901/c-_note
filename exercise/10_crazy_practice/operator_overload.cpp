#include <iostream>
#include <cstring>

class String
{
	int len;
	const char *pch;
public:
	String(const char *str = ""):pch(str), len(strlen(str)){}
	int stringlen(){return len;}
	friend std::ostream &operator<<(std::ostream &out, const String &s);
	friend std::istream &operator>>(std::istream &in, const String &s);
	bool operator==(const String &s);
	bool operator!=(const String &s);
	bool operator!();
	bool operator<(const String &s);
	bool operator>(const String &s);
	~String(){delete pch;}
};

std::ostream &operator<<(std::ostream &out, const String &s)
{
	return out << s.pch;
}

std::istream &operator>>(std::istream &in, const String &s)
{
	return in >> s.pch;
}

bool String::operator==(const String &s)
{
	return s.pch == pch;
}

bool String::operator!=(const String &s)
{
	return s.pch != pch;
}

bool String::operator!()
{
	return len == 0;
}

bool String::operator<(const String &s)
{
	return pch < s.pch;
}

bool String::operator>(const String &s)
{
	return pch > s.pch;
}

int main()
{
	String s1("I am a string"), s2("I am a string too"), s3;
	std::cout << s1 << std::endl;
	std::cout << (s1 < s2) << std::endl;
	std::cout << (s1 > s2) << std::endl;
	std::cout << !s3;
	std::cin >> s3;
	return 0;
}
