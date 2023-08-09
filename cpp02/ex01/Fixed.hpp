#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int fixedNbr;
		static const int fractionalBits = 8;
	public:
		std::string x;
		Fixed();
		Fixed(Fixed const& fixed);
		Fixed(int nbr);
		Fixed(float nbr);
		~Fixed();
		Fixed&	operator=(Fixed const& fixed);
		float	toFloat()  const;
		int		getRawBits() const;
		int		toInt()  const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif