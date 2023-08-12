#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(){
    std::cout << this->_name << ": bye world" << std::endl;
	system("leaks Zombie");
}

void Zombie::announce(){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}