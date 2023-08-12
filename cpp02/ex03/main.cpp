#include "Point.hpp"

int main( void ) 
{
	Point a(0, 0);
	Point b(0, 2);
	Point c(2, 0);
	Point point(0.5, 0);
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0; 
}
