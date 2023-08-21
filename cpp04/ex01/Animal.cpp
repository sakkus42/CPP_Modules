#include "Animal.hpp"

Animal::Animal() : type(""){
    std::cout << "Animal Constructor Run" << std::endl;
}

Animal::Animal(std::string _type) : type(_type){
    std::cout << "Animal Type Paramtre Constructor Run" << std::endl;
}

Animal::Animal(Animal const& animal){
    std::cout << "Animal Copy Constructor Run" << std::endl;
    *this = animal;
}

Animal::~Animal(){
    std::cout << "Animal Destructor Run" << std::endl;
}

Animal& Animal::operator=(Animal const& animal){
    std::cout << "Animal Asignment Operator Overloading" << std::endl;
    this->type = animal.type;
    return (*this);
}

void Animal::makeSound() const{
    std::cout << "Animals can make sounds" << std::endl;
}

std::string Animal::getType() const{
    return (this->type);
}