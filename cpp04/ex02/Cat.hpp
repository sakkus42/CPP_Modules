#include "Brain.hpp"

class Cat : public AAnimal{
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
    
        Cat& operator=(Cat const& cat);
        void makeSound() const;
};