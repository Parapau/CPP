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
		int		operator>(const Fixed &og);
		int		operator>=(const Fixed &og);
		int		operator<(const Fixed &og);
		int		operator<=(const Fixed &og);
		int		operator!=(const Fixed &og);
		float	operator+(const Fixed &og);
		float	operator-(const Fixed &og);
		float	operator*(const Fixed &og);
		float	operator/(const Fixed &og);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		~Fixed(void);

		static Fixed const	min(Fixed &num1, Fixed &num2);
		static Fixed const	min(const Fixed &num1, const Fixed &num2);
		static Fixed const	max(Fixed &num1, Fixed &num2);
		static Fixed const	max(const Fixed &num1, const Fixed &num2);

		int			toInt(void) const;
		float		toFloat(void) const;

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream  &os, Fixed const &og);

#endif
