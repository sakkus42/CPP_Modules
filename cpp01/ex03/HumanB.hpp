#ifndef HumanB_HPP
#define HumanB_HPP

#include "Weapon.hpp"

class HumanB{
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(std::string name);
        void    setWeapon(Weapon& weapon);
        void    attack();
};

#endif