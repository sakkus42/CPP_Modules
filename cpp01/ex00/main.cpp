#include "Zombie.hpp"

int main(){
    Zombie z("sülo");
    z.announce();
    Zombie *z1 =  Zombie::newZombie("aho");
    z1->announce();
    Zombie::randomChump("ysf");
    delete z1;
}