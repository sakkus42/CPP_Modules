#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap default constructor run" << std::endl;
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name){
    std::cout << "ScavTrap constructor run" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor run" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " + this->name + " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(std::string const& target){
    if (this->energyPoints == 0){
        std::cout << "ScavTrap " + this->name + " energy points are exhausted" << std::endl;
    }else if(this->hitPoints == 0){
        std::cout << "ScavTrap " + this->name + " in need of renovation" << std::endl;
    }else{
        std::cout << "ScavTrap " + this->name + " attacks " + target + " causing " << this->attackDamage << " points of damage !" << std::endl;
        this->energyPoints--;
    }
}