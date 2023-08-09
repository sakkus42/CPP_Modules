#include "Fixed.hpp"

int main(){
	Fixed a;
	Fixed b(10);
	Fixed c(12.23f);
	std::cout << (2 << 8) << std::endl;
	a = b;
	std::cout << a.toInt() << std::endl;
	std::cout << b.toInt() << std::endl;
	std::cout << c.toInt() << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}