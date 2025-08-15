#include "../Fixed.hpp"

//CONSTRUCTORS

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << _fract);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(num * (1 << _fract)));
}

Fixed::Fixed(const Fixed &og)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = og.getRawBits();
}

//DESTRUCTOR`S

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//OVERLOADS

Fixed	&Fixed::operator=(const Fixed &og)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &og)
		this->_rawBits = og.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &o, const Fixed &og)
{
	o << og.toFloat();
	return (o);
}

//FUNCTIONS

int		Fixed::toInt(void) const
{
	return (getRawBits() >> 8);
}

float	Fixed::toFloat(void) const
{/*
	float	ret;
	int		num;
	int		i;
	int		pwr;

	num = getRawBits();
	ret = num >> 8;
	i = _fract;
	pwr = 2;
	while (i > 0)
	{
		ret += (float) (num & i) / pwr;
		pwr *= 2;
		i--;
	}
	return (ret);
	*/
	return ((float) _rawBits / (1 << _fract));
}

//GETTERS

int	Fixed::getRawBits() const
{
	return (this->_rawBits);
}

//SETTERS

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
