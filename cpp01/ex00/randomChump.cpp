#include "Zombie.hpp"

void Zombie::randomChump(std::string name){
    Zombie stackZomb(name);
    stackZomb.announce();
}