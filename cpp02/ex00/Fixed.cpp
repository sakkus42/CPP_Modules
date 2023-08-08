#include "Fixed.hpp"

Fixed::Fixed() : fixedNbr(0) {
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(Fixed& fixed){
    std::cout << "Copy Constructor Called" << std::endl;
    this->setRawBits(fixed.getRawBits());
}

Fixed::~Fixed() {
    std::cout << "Destructor Called" << std::endl;
}

void Fixed::operator=(Fixed fixed){
    std::cout << "Copy Assignment Operator Called" << std::endl;
    this->setRawBits(fixed.getRawBits());
}

int Fixed::getRawBits() {
    std::cout << "getRawBits Member Function Called" << std::endl;
    return (this->fixedNbr);
}

void    Fixed::setRawBits(int nbr){
    this->fixedNbr = nbr;
}
