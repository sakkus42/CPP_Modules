#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (size_t i = 0; i < 4; i++)
    {
        this->sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const& src){
    *this = src;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->sources[i]) delete this->sources[i];
    }
    
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src){
    for (size_t i = 0; i < 4; i++)
    {
        this->sources[i] = src.sources[i];
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *a){
    for (size_t i = 0; i < 4; i++)
    {
        if (this->sources[i] == NULL){
            this->sources[i] = a;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type){
    for (size_t i = 0; i < 4; i++)
    {
        if (this->sources[i] && this->sources[i]->getType() == type){
            return (this->sources[i]->clone());
        }
    }
    return (0);
}
