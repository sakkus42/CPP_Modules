#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "🐱Cat🐱 constructor" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "🐱Cat🐱 destructor" << std::endl;
}

Cat& Cat::operator=(Cat const& cat){
    std::cout << "🐱Cat🐱 asignment operator ovr" << std::endl;
    this->type = cat.type;
    this->brain = new Brain(*cat.brain);
    return (*this);
}
void Cat::makeSound() const{
    std::cout << "🐱🐱 miyav miyav.." << std::endl;
}

