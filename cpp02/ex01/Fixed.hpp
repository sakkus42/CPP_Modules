#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int fixedNbr;
        static const int factionalBits = 8;
    public:
        Fixed();
        Fixed(Fixed& fixed);
        Fixed(int intValue);
        Fixed(float floatValue);
        ~Fixed();
        Fixed&    operator=(Fixed& fixed);
        int     getRawBits();
        void    setRawBits(int nbr);
        int     toInt();
};

#endif