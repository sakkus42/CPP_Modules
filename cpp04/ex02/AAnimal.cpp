#include "AAnimal.hpp"

AAnimal::AAnimal() : type(""){
    std::cout << "AAnimal Constructor Run" << std::endl;
}

AAnimal::AAnimal(std::string _type) : type(_type){
    std::cout << "AAnimal Type Paramtre Constructor Run" << std::endl;
}

AAnimal::AAnimal(AAnimal const& animal){
    std::cout << "AAnimal Copy Constructor Run" << std::endl;
    *this = animal;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal Destructor Run" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& animal){
    std::cout << "AAnimal Asignment Operator Overloading" << std::endl;
    this->type = animal.type;
    return (*this);
}

void AAnimal::makeSound() const{
    std::cout << "AAnimals can make sounds" << std::endl;
}

std::string AAnimal::getType() const{
    return (this->type);
}