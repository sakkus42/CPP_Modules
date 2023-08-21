#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(Brain const& brain){
    std::cout << "Brain Copy Constructor" << std::endl;
    *this = brain;
}

Brain::~Brain(){
    std::cout << "Brain Destructor" << std::endl;   
}

Brain& Brain::operator=(Brain const& brain){
    std::cout << "Brain asignment operator" << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}