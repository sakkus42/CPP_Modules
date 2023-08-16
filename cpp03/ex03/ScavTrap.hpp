#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    protected:
        ScavTrap();
    public:
        ScavTrap(std::string const& name);
        ~ScavTrap();
        void guardGate();
        void attack(std::string const& target);
};