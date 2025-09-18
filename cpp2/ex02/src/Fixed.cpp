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
	this->_rawBits = og.getRawBits();
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
	this->_rawBits++;
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
	this->_rawBits--;
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
	if (getRawBits() >= 0)
		return (getRawBits() >> this->_fract);
	if (getRawBits() << (32 - this->_fract) != 0)
		return ((getRawBits() >> this->_fract) + 1);
	return (getRawBits() >> this->_fract);
}

float	Fixed::toFloat(void) const
{
	return ((float) getRawBits() / (1 << this->_fract));
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
