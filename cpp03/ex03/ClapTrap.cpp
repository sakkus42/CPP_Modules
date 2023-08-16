#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name){
    std::cout << "ClapTrap constructor Run" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Default Constructor Run" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap){
    std::cout << "ClapTrap Copy Constructor Run" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructors Run" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap){
    std::cout << "ClapTrap Copy Asignmet Operator Run" << std::endl;
    this->name = clapTrap.name;
    this->attackDamage = clapTrap.attackDamage;
    this->energyPoints = clapTrap.energyPoints;
    this->hitPoints = clapTrap.hitPoints;
    return (*this);
}

void ClapTrap::attack(const std::string& target){
    if (this->energyPoints == 0){
        std::cout << "ClapTrap " + this->name + " energy points are exhausted" << std::endl;
    }else if(this->hitPoints == 0){
        std::cout << "ClapTrap " + this->name + " in need of renovation" << std::endl;
    }else{
        std::cout << "ClapTrap " + this->name + " attacks " + target + " causing " << this->attackDamage << " points of damage !" << std::endl;
        this->energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitPoints <= amount){
        std::cout <<"ClapTrap " + this->name + " is dead" << std::endl;
        this->hitPoints = 0;
        return ;
    }
    std::cout << "ClapTrap " + this->name + " takes" << amount << " damage" << std::endl;
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energyPoints <= amount){
        std::cout << "ClapTrap " + this->name + " energy points are exhausted" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " + this->name + " regenerated itself up to " << amount << " hit points" << std::endl;
    this->energyPoints--;
    this->hitPoints += amount;
}