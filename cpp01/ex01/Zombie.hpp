#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void announce();
        static Zombie* zombieHorde(int n, std::string name);
        void    set_name(std::string name);
};

#endif