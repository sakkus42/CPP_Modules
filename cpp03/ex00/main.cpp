#include "ClapTrap.hpp"

int main(){
    ClapTrap clp1("Ahmet");
    ClapTrap clp2("Samet");
    clp1.attack("selami");
    clp2.attack("memo");
    clp1.takeDamage(25);
    clp2.takeDamage(25);
    clp1.attack("selami");
    clp2.attack("memo");
    clp1.beRepaired(1);
    clp2.beRepaired(5);
    clp1.attack("selami");
    clp2.attack("memo");
}