#include "AMateria.hpp"

AMateria::AMateria(std::string const& _type) : type(_type) {}

AMateria::AMateria(AMateria const& amateria){
    *this = amateria;
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const{
    return this->type;
}

AMateria* AMateria::clone() const{
    std::cout << this << std::endl;
    return ((AMateria*)this);
};

void AMateria::use(ICharacter& target){
    std::cout << "AMetaria "+this->type+" used on "+target.getName() << std::endl;
}
