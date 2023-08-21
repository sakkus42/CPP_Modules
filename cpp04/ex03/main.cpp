#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

class Fire : public AMateria{
    public:
        Fire() : AMateria("fire") {}

        void use(ICharacter& target){
            std::cout << "* shoots an fire bolt at " + target.getName() + " *" << std::endl;
        }

        AMateria* clone() const{
            return (new Fire());
        }
};

class Enemy : public ICharacter{
    private:
        std::string name;
        AMateria *gun;
    public:
        Enemy(std::string _name) : name(_name){
            this->gun = NULL;
        }

        std::string const& getName() const {
            return this->name;
        }

        void equip(AMateria* m){
            this->gun = m;
        }

        void unequip(int idx){
            (void)idx;
            delete this->gun;
            this->gun = NULL;
        }

        void use(int idx, ICharacter& target){
            (void)idx;
            if (this->gun){
                this->gun->use(target);
            }
        }
};


int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    std::cout << "--------------------" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Fire());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        me->equip(src->createMateria("fire"));
        me->equip(src->createMateria("ice"));
        me->equip(src->createMateria("cure"));

        ICharacter* enemy = new Enemy("enemy");
        enemy->equip(src->createMateria("cure"));
        me->use(0, *enemy);
        enemy->use(0, *enemy);
    }
}