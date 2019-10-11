#include <iostream>
int main()
{
	int a{5};
	a = 43;
	std::cout << a << std::endl;

	double b{5.5};
	std::cout << b << std::endl;

	int c{b};
	std::cout << c << std::endl;	
}

