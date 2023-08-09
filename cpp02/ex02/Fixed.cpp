#include "Fixed.hpp"

Fixed::Fixed() : fixedNbr(0) {}

Fixed::Fixed(Fixed& fixed){
	this->fixedNbr = fixed.getRawBits();
}

Fixed::Fixed(int nbr){
	this->fixedNbr = nbr;
}

Fixed::Fixed(float nbr){
	this->fixedNbr = std::roundf(nbr * (1 << fractionalBits));
}

Fixed& Fixed::operator=(Fixed const& fixed){
	this->fixedNbr = fixed.getRawBits() >> fractionalBits;
	return *this;
}

int	Fixed::getRawBits() const{
	return (this->fixedNbr << fractionalBits);
}

float Fixed::toFloat() const{
	return (((float)this->fixedNbr) / (1 << fractionalBits));
}

int		Fixed::toInt() const{
	return (this->fixedNbr >> fractionalBits);
}

std::ostream& operator<<(std::ostream& os, Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}