#include <iostream>

class ClapTrap{
    protected:
        std::string  name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
        ClapTrap();
    public:
        ClapTrap(std::string const& name);
        ClapTrap(const ClapTrap& clapTrap);
        ~ClapTrap();

        ClapTrap& operator=(const ClapTrap& clapTrap);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};