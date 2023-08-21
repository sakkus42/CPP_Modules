#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    std::cout << "🐶Dog🐶 constructor" << std::endl;
}

Dog::~Dog(){
    std::cout << "🐶Dog🐶 destructor" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "🐶🐶 Hav Hav.." << std::endl;
}

