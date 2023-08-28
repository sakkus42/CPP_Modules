#include "Zombie.hpp"

void func(){
	Zombie *a = new Zombie("süleyman");
	a->announce();
	delete a;
}

int main(){
    Zombie z("sülo");
    z.announce();
    Zombie *z1 =  Zombie::newZombie("aho");
	z1 =  Zombie::newZombie("zaho");
    z1->announce();
    Zombie::randomChump("ysf");
	delete z1;
}