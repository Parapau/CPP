#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fract = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &og);
		Fixed	&operator=(const Fixed &og);
		~Fixed(void);

		int			toInt(void) const;
		float		toFloat(void) const;

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream  &os, Fixed const &og);

#endif
