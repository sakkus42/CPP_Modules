#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "~FragTrap~ Default Constructor Run" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "~FragTrap~ Constructor Run" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap(){
    std::cout << "~FragTrap~ Decostructor Run" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (this->energyPoints == 0){
        std::cout << "~FragTrap~ " + this->name + " energy points are exhausted" << std::endl;
        return;
    }
    std::cout << "~FragTrap~ " + this->name + " high fives" + " energy:" << --this->energyPoints << std::endl;
}