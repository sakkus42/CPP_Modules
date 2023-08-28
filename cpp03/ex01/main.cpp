#include "ScavTrap.hpp"

int main(){
    ScavTrap trp("selami");
    ClapTrap trp1("asd");
    trp.attack("asd");
    trp1.attack("hi");
    trp.attack("asd");
    trp1.attack("hi");
	trp.guardGate();
}