#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria *sources[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const& src);
        ~MateriaSource();

        MateriaSource& operator=(MateriaSource const& src);
        void learnMateria(AMateria *mtr);
        AMateria* createMateria(std::string const& type);
};


#endif