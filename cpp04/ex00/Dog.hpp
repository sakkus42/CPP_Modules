#include "Cat.hpp"

class Dog : public Animal{
    public:
        Dog();
        ~Dog();
        void makeSound() const;
};