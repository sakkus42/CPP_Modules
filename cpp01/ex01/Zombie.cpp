#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(){
    std::cout << this->_name << ": bye world" << std::endl;
}

void Zombie::announce(){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
    this->_name = name;
}