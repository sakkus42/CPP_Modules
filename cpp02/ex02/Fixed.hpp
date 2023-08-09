#include <iostream>
#include <cmath>

class Fixed{
	private:
		int					fixedNbr;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed& fixed);
		Fixed(int nbr);
		Fixed(float nbr);
		Fixed&	operator=(Fixed const& fixed);
		int		getRawBits() const;
		int		toInt() const;
		float	toFloat() const;
};

std::ostream& operator<<(std::ostream& os, Fixed& fixed);