#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    private:
        std::string name;
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();

        void attack(std::string const& name);
        void whoAmI();
};