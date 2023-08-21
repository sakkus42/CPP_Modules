#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const& other) : AMateria("cure") 
{
    *this = other;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(Cure const& src){
    this->type = src.type;
    return (*this);
}

AMateria* Cure::clone() const {
    return (new Cure());
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
}
