/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:49:59 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:53:00 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Dog.hpp"

//CONSTRUCTOR

Dog::Dog(void)
{
//	std::cout << "Constructing a dog" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog &og)
{
//	std::cout << "Cloning a dog" << std::endl;
	this->_type = og.getType();
}

//OVERLOADS

Dog	&Dog::operator=(Dog &og)
{
//	std::cout << "Dog assignement operator called" << std::endl;
	this->_type = og.getType();
	return (*this);
}

//METHODS

void	Dog::makeSound(void) const
{
	std::cout << "Bub Bub Bub" << std::endl;
}

//DESTRUCTORS

Dog::~Dog(void)
{
	std::cout << "Making mocasines saltarines" << std::endl;
}
