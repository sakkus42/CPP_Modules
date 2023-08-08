#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedNbr(0) {}

Fixed::Fixed(Fixed& fixed) {
    *this = fixed;
}

Fixed::Fixed(int value) : fixedNbr(value) {}

Fixed::Fixed(float value) : fixedNbr(std::roundf(value * (1 << factionalBits))) {}

Fixed::~Fixed(){}

Fixed&    Fixed::operator=(Fixed& fixed){
    *this = fixed;
    return *this;
}

int Fixed::getRawBits(){
    return (this->fixedNbr);
}

void Fixed::setRawBits(int nbr){
    this->fixedNbr = nbr;
}

int Fixed::toInt(){
    return this->fixedNbr >> factionalBits;
}
