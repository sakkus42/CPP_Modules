#include "Animal.hpp"

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain const& brain);
        ~Brain();
        Brain& operator=(Brain const& brain);
};