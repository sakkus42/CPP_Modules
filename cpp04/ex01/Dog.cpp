#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    std::cout << "🐶Dog🐶 constructor" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog(){
    delete this->brain;
    std::cout << "🐶Dog🐶 destructor" << std::endl;
}

Dog& Dog::operator=(Dog const& dog){
    std::cout << "🐶Dog🐶 asignment oprtr ovr" << std::endl;
    this->type = dog.type;
    this->brain = new Brain(*dog.brain);
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "🐶🐶 Hav Hav.." << std::endl;
}

