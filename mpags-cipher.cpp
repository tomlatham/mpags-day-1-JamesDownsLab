#include <iostream>
#include <string>
int main()
{
	int a{5};
	a = 43;
	std::cout << a << std::endl;

	double b{5.5};
	std::cout << b << std::endl;

	int c{3};
	std::cout << c << std::endl;	

	const double d{7.2};
	std::cout << d << std::endl;

	int e{7};
	e = 5;

	std::string msg {"Hello"};
	std::cout << msg << "\n";

	return 0;
}

