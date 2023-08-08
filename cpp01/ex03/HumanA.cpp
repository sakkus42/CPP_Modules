#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){} 

void HumanA::attack(){
    std::cout << _name << ":";
    if (_weapon.get_type() == ""){
        std::cout << "i don't have a gun" << std::endl;
    }else{
        std::cout << _weapon.get_type() << std::endl;
    }
}