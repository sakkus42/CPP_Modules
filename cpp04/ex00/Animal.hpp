#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const& animal);
        ~Animal();
        Animal& operator=(Animal const& animal);

        virtual void makeSound() const;
        std::string getType() const;
};