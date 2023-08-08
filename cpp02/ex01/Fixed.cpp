#include "Fixed.hpp"

Fixed::Fixed() : fixedNbr(0) {}

Fixed::Fixed(int nbr) : fixedNbr(nbr << 8) {}

Fixed::Fixed(float nbr) {
	fixedNbr = std::roundf(nbr * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const& fixed) {
	this->fixedNbr = fixed.getRawBits();
}

void	Fixed::operator=(Fixed const& fixed){
	this->fixedNbr = fixed.getRawBits();
}

int	Fixed::getRawBits() const{
	return (this->fixedNbr);	
}

int Fixed::toInt() const{
	return (fixedNbr >> fractionalBits);
}

int Fixed::toFloat() const{
	std::cout <<"fixed: " << fixedNbr << std::endl;
	return (static_cast<float>(fixedNbr / (1 << fractionalBits)));
}
