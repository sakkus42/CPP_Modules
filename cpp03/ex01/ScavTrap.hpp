#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    protected:
        ScavTrap();
    public:
        ScavTrap(std::string const& name);
        ~ScavTrap();
        void guardGate();
        void attack(std::string const& target);
};