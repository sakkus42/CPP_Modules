#include <iostream>
#include <cmath>

class Fixed{
	private:
		int					fixedNbr;
		static const int	fractionalBits = 8;		
	public:
		Fixed();
		Fixed(Fixed const& fixed);
		Fixed(int nbr);
		Fixed(float nbr);

		Fixed&	operator=(Fixed const& fixed);

		int		getRawBits() const;
		int		toInt() const;
		float	toFloat() const;

		bool	operator<(Fixed const& fixed) const;
		bool	operator<=(Fixed const& fixed) const;
		bool	operator>=(Fixed const& fixed) const;
		bool	operator>(Fixed const& fixed) const;
		bool	operator==(Fixed const& fixed) const;
		bool	operator!=(Fixed const& fixed) const;

		Fixed	operator+(Fixed const& fixed) const;
		Fixed	operator-(Fixed const& fixed) const;
		Fixed	operator*(Fixed const& fixed) const;
		Fixed	operator/(Fixed const& fixed) const;
		
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed operator--(int);
		Fixed operator++(int);

		static Fixed& min(Fixed& fix1, Fixed& fix2);
		static const Fixed& min(Fixed const& fix1, Fixed const& fix2);
		static Fixed& max(Fixed& fix1, Fixed& fix2);
		static const Fixed& max(Fixed const& fix1, Fixed const& fix2);
};

std::ostream& operator<<(std::ostream& os, Fixed fixed);
