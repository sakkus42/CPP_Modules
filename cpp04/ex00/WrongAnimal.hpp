#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const& animal);
        ~WrongAnimal();
        WrongAnimal& operator=(WrongAnimal const& animal);

        void makeSound() const;
        std::string getType() const;
};