#include "Fixed.hpp"
#include <stdio.h>

class Osman{
	public:
		Osman(){
			std::cout << "SES\n";
		}
		Osman(int str){
			std::cout << "osman:" << str << std::endl;
		}
		
};

	int main( void ) {
		Fixed a;
		const Fixed  b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		std::cout << "first a:"  << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		std::cout << d.getRawBits() << std::endl;
		a = Fixed( 1234.4321f );
		Osman os = 32;

		(void)os;
		// std::cout << "change a:"  << a.getRawBits() << std::endl;
		// std::cout << "a is " << a << std::endl;
		// std::cout << "b is " << b << std::endl;
		// std::cout << "c is " << c << std::endl;
		// std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		std::cout << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << "d is " << d.toFloat() << " as float" << std::endl;
		return 0;
	}