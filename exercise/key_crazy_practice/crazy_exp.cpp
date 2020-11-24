#include <iostream>

auto func(int n) -> void
{
	try{
		if (n <= 0)
			throw "error!";
		else
			std::cout << "n=" << n;
	}catch(const char * e){
		std::cout << e << std::endl;
		throw n;
	}
}

int main(int argc, char const *argv[])
{
	try{
		func(-1);
	}catch(int n){
		std::cout << "at main.cpp";
	}
	return 0;
}
