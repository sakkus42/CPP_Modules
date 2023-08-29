#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
    }
    {
        std::cout << std::endl << std::endl << "Wrong1"  << std::endl << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); 
        meta->makeSound();
    }
    {
        std::cout << std::endl << std::endl << "Wrong2"  << std::endl << std::endl;
        const Animal meta;
        const Animal j = Cat();
        const Animal i = Dog();
        std::cout << j.getType() << " " << std::endl;
        std::cout << i.getType() << " " << std::endl;
        i.makeSound();
        j.makeSound();
        meta.makeSound();
    }
    return 0;
}