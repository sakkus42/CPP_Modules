#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "🐱Cat🐱 constructor" << std::endl;
}

Cat::~Cat(){
    std::cout << "🐱Cat🐱 destructor" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "🐱🐱 miyav miyav.." << std::endl;
}

