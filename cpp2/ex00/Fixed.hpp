#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fract = 8;
	public:
		Fixed(void);
		Fixed(Fixed &og);
		Fixed	&operator=(Fixed &og);
		~Fixed(void);

		int					getRawBits(void);
		void				setRawBits(int const raw);
};

#endif
