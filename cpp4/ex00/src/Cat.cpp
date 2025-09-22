/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:43:41 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:41:42 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cat.hpp"

//CONSTRUCTOR

Cat::Cat(void)
{
	//std::cout << "Constructing a cat" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat &og)
{
	//std::cout << "Cloning a cat" << std::endl;
	this->_type = og.getType();
}

//OVERLOADS

Cat	&Cat::operator=(Cat &og)
{
	//std::cout << "Cat assignement operator called" << std::endl;
	this->_type = og.getType();
	return (*this);
}

//METHODS

void	Cat::makeSound(void) const
{
	std::cout << "Marrameu" << std::endl;
}

//DESTRUCTORS

Cat::~Cat(void)
{
	std::cout << "A cat has been killed" << std::endl;
}
