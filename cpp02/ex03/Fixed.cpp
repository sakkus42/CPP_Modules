#include "Fixed.hpp"

Fixed::Fixed() : fixedNbr(0) {}

Fixed::Fixed(Fixed const& fixed){
	this->fixedNbr = fixed.getRawBits();
}

Fixed::Fixed(int nbr) : fixedNbr(nbr << fractionalBits) {}

Fixed::Fixed(float nbr) : fixedNbr(std::roundf(nbr * (1 << fractionalBits))) {}

Fixed& Fixed::operator=(Fixed const& fixed){
	this->fixedNbr = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const{
	return (this->fixedNbr);
}

float Fixed::toFloat() const{
	return ((this->fixedNbr) / (float)(1 << fractionalBits));
}

int		Fixed::toInt() const{
	return (this->fixedNbr >> fractionalBits);
}

// comparison operator
bool	Fixed::operator<(Fixed const& fixed) const{
	return (this->getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator>(Fixed const& fixed) const{
	return (this->getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const& fixed) const{
	return (this->getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const& fixed) const{
	return (!(this->operator==(fixed)));
}

bool	Fixed::operator>=(Fixed const& fixed) const{
	return (this->operator==(fixed) || this->operator>(fixed));
}

bool	Fixed::operator<=(Fixed const& fixed) const{
	return (this->operator==(fixed) || this->operator<(fixed));
}

// arithmetic operator
Fixed	Fixed::operator+(Fixed const& fixed) const{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(Fixed const& fixed) const{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(Fixed const& fixed) const{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(Fixed const& fixed) const{
	return Fixed(this->toFloat() / fixed.toFloat());
}



// Increment/Decrement

Fixed&	Fixed::operator++(void){
	this->fixedNbr++;
	return (*this);
}

Fixed&	Fixed::operator--(void){
	this->fixedNbr--;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed res(*this);
	this->fixedNbr--;
	return (res);
}

Fixed	Fixed::operator++(int){
	Fixed res(*this);
	this->fixedNbr++;
	return (res);
}

// max min

Fixed& Fixed::min(Fixed& fix1, Fixed& fix2){
	if (fix1 < fix2){
		return (fix1);
	}else{
		return (fix2);
	}
}

const Fixed& Fixed::min(Fixed const& fix1, Fixed const& fix2){
	if (fix1 < fix2){
		return (fix1);
	}else{
		return (fix2);
	}
}

Fixed& Fixed::max(Fixed& fix1, Fixed& fix2){
	if (fix1 > fix2){
		return (fix1);
	}else{
		return (fix2);
	}
}

const Fixed& Fixed::max(Fixed const& fix1, Fixed const& fix2){
	if (fix1 > fix2){
		return (fix1);
	}else{
		return (fix2);
	}
}


std::ostream& operator<<(std::ostream& os,  Fixed fixed){
	os << fixed.toFloat();
	return (os);
}