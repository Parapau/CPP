/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:08:45 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:42:21 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Animal.hpp"

//CONSTRUCTORS

Animal::Animal(void)
{
//	std::cout << "Animal base constructor called" << std::endl;
	this->_type = "Gambusino";
}

Animal::Animal(Animal &og)
{
//	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = og.getType();
}

//OVERLOADS

Animal	&Animal::operator=(Animal &og)
{
//	std::cout << "Animal assignement overload called" << std::endl;
	this->_type = og.getType();
	return (*this);
}

//GETTERS

std::string	Animal::getType(void) const
{
	return (this->_type);
}

//SETTERS

void	Animal::setType(const std::string type)
{
	this->_type = type;
}

//METHODS

void	Animal::makeSound(void) const
{
	std::cout << "AAJJHSJFHSJDFLKDJBNSDJHGPAEFAJBRGAJDFGLKJDSJBLKJSDFGPJJF" << std::endl;
}

//DESTRUCTORS

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}
