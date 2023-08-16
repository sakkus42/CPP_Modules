#include "FragTrap.hpp"

int main(){
    FragTrap fgt("Süleyman");
    FragTrap fgt1(fgt);

    fgt.attack("fgt");
    fgt.highFivesGuys();
    fgt1.highFivesGuys();
}