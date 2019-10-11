#include <iostream>
#include <string>
int main()
{
	int a{5};
	a = 43;
	std::cout << a << std::endl;

	double b{5.5};
	std::cout << b << std::endl;

	std::cout << a*b <<std::endl;

	std::cout << a/b <<std::endl;

	std::cout << a/a << std::endl;

	std::string msg{"Hello World"};

	char letter {msg[4]};
	std::cout << letter <<std::endl;
	
	return 0;
}

