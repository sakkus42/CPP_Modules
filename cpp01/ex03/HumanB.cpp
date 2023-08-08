#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    _weapon = NULL;
}

void    HumanB::attack(){
    std::cout << _name << ":";
    if (_weapon->get_type() == "" || _weapon == NULL){
        std::cout << "i don't have a gun" << std::endl;
    }else{
        std::cout << _weapon->get_type() << std::endl;
    }

}

void    HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}