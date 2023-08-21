#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type(""){
    std::cout << "WrongAnimal Constructor Run" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type){
    std::cout << "WrongAnimal Type Paramtre Constructor Run" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& animal){
    std::cout << "WrongAnimal Copy Constructor Run" << std::endl;
    *this = animal;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor Run" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& animal){
    std::cout << "WrongAnimal Asignment Operator Overloading" << std::endl;
    this->type = animal.type;
    return (*this);
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimals can make sounds" << std::endl;
}

std::string WrongAnimal::getType() const{
    return (this->type);
}