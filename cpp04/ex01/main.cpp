#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    const Animal* animalArray[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
    for (size_t i = 0; i < 4; i++)
    {
        delete animalArray[i];
    }
    return 0;
}