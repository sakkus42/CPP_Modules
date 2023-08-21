#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const& other) : AMateria("ice") 
{
    *this = other;
}

Ice::~Ice()
{
}

Ice& Ice::operator=(Ice const& src){
    this->type = src.type;
    return (*this);
}

AMateria* Ice::clone() const {
    return (new Ice());
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}
