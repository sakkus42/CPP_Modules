#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

	class Fixed{
		private:
			int fixedNbr;
			static const int fractionalBits = 8;
		public:
			Fixed();
			Fixed(Fixed const& fixed);
			Fixed(int nbr);
			Fixed(float nbr);
			void	operator=(Fixed const& fixed);
			int		getRawBits() const;
			int		toInt()  const;
			int		toFloat()  const;
	};

#endif