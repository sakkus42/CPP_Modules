#include "Cat.hpp"

class Dog : public AAnimal{
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        Dog& operator=(Dog const& dog);
        void makeSound() const;
};