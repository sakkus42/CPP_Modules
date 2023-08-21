#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat"){
    std::cout << "🐱Cat🐱 constructor" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "🐱Cat🐱 destructor" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "🐱🐱 miyav miyav.." << std::endl;
}

