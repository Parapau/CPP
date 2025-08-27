#include "../Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(Fixed &og)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = og.getRawBits();
} 

Fixed	&Fixed::operator=(Fixed &og)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &og)
		this->_rawBits = og.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits()
{
	std::cout << "getRawBits called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_rawBits = raw;
}
