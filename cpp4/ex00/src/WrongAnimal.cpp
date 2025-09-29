/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:08:45 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/29 20:43:20 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WrongAnimal.hpp"

//CONSTRUCTORS

WrongAnimal::WrongAnimal(void)
{
//	std::cout << "Animal base constructor called" << std::endl;
	this->_type = "Gambusino";
}

WrongAnimal::WrongAnimal(WrongAnimal &og)
{
//	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = og.getType();
}

//OVERLOADS

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &og)
{
//	std::cout << "Animal assignement overload called" << std::endl;
	this->_type = og.getType();
	return (*this);
}

//GETTERS

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

//SETTERS

void	WrongAnimal::setType(const std::string type)
{
	this->_type = type;
}

//METHODS

void	WrongAnimal::makeSound(void) const
{
	std::cout << "AAJJHSJFHSJDFLKDJBNSDJHGPAEFAJBRGAJDFGLKJDSJBLKJSDFGPJJF" << std::endl;
}

//DESTRUCTORS

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "This animal has been put out of it's misery" << std::endl;
}
