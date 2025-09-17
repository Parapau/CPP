#include "../Fixed.hpp"

//CONSTRUCTORS

Fixed::Fixed()
{
	std::cout << "Constructor pocho >:(" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const int num)
{
	setRawBits(num << _fract);
}

Fixed::Fixed(const float num)
{
	setRawBits(roundf(num * (1 << _fract)));
}

Fixed::Fixed(const Fixed &og)
{
	_rawBits = og.getRawBits();
}

//DESTRUCTOR`S

Fixed::~Fixed()
{
}

//OVERLOADS

Fixed	&Fixed::operator=(const Fixed &og)
{
	if (this != &og)
		this->_rawBits = og.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &o, const Fixed &og)
{
	o << og.toFloat();
	return (o);
}

int	Fixed::operator>(const Fixed &og)
{
	return (this->toFloat() > og.toFloat());
}

int	Fixed::operator>=(const Fixed &og)
{
	return (this->toFloat() >= og.toFloat());
}

int	Fixed::operator<(const Fixed &og)
{
	return (this->toFloat() < og.toFloat());
}

int	Fixed::operator<=(const Fixed &og)
{
	return (this->toFloat() <= og.toFloat());
}

int	Fixed::operator!=(const Fixed &og)
{
	return (this->toFloat() != og.toFloat());
}

float	Fixed::operator+(const Fixed &og)
{
	return (this->toFloat() + og.toFloat());
}

float	Fixed::operator-(const Fixed &og)
{
	return (this->toFloat() - og.toFloat());
}

float	Fixed::operator*(const Fixed &og)
{
	return (this->toFloat() * og.toFloat());
}

float	Fixed::operator/(const Fixed &og)
{
	return (this->toFloat() / og.toFloat());
}

Fixed	&Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old;

	old = *this;
	operator++();
	return (old);
}

Fixed	&Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old;

	old = *this;
	operator--();
	return (old);
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

Fixed const	Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed const	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const	Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

Fixed const	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
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
