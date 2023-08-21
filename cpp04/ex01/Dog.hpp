#include "Cat.hpp"

class Dog : public Animal{
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        Dog& operator=(Dog const& dog);
        void makeSound() const;
};