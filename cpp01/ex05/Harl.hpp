#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
    private:
        typedef         void(Harl::*funcsPointer) ();
        void            debug();
        void            info();
        void            warning();
        void            error();
    public:
        void            complain(std::string level);
};

#endif