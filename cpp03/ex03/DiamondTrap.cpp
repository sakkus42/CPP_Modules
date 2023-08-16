#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name){
    std::cout << "DimondTrap constructor Run" << std::endl;
    this->name = name;
    ClapTrap::name = this->name + "_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor Run" << std::endl;
}

void DiamondTrap::attack(std::string const& name){
    std::cout << "Called by ScavTrap::attack() ";
    ScavTrap::attack(name);
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap My name is " + this->name + " ClapTrap Name is " + ClapTrap::name << std::endl;
}