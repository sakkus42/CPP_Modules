#include "Fixed.hpp"

Fixed::Fixed() : fixedNbr(0) {
	x = std::string("test");
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int nbr) : fixedNbr(nbr << 8) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float nbr) {
	std::cout << "Float constructor called" << std::endl;
	fixedNbr = std::roundf(nbr * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixedNbr = fixed.getRawBits();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& fixed){
	this->fixedNbr = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const{
	return (this->fixedNbr);	
}

int Fixed::toInt() const{
	return (fixedNbr >> fractionalBits);
}

float Fixed::toFloat() const{
	float nbr = (float)getRawBits();
	return  (nbr / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed){
	os << fixed.toFloat();
	return os;
}