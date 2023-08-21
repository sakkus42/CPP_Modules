#include "Character.hpp"

Character::Character(std::string const& name){
    this->name = name;
    for (size_t i = 0; i < 4; i++)
    {
        this->slots[i] = NULL;
    }
}

Character::Character(Character const& other){
    this->name = other.name;
    for (size_t i = 0; i < 4 && other.slots[i]; i++)
    {
        this->slots[i] = other.slots[i];
    }
}

Character::~Character() 
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->slots[i]) delete this->slots[i];
    }
}

Character& Character::operator=(Character const& src){
    this->name = src.name;
    for (size_t i = 0; i < 4 && src.slots[i]; i++)
    {
        this->slots[i] = src.slots[i];
    }
    return (*this);
}

std::string const& Character::getName() const{
    return (this->name);
}

void Character::equip(AMateria* m){
    for (size_t i = 0; i < 4; i++){
        if(this->slots[i] == NULL){
            this->slots[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx){
    if (this->slots[idx]){
        delete this->slots[idx];
        this->slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target){
    if (this->slots[idx]){
        this->slots[idx]->use(target);
    }
}