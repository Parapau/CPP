/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:43:41 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:48:47 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WrongCat.hpp"

//CONSTRUCTOR

WrongCat::WrongCat(void)
{
	//std::cout << "Constructing a cat" << std::endl;
	this->_type = "Cat";
}

WrongCat::WrongCat(WrongCat &og)
{
	//std::cout << "Cloning a cat" << std::endl;
	this->_type = og.getType();
}

//OVERLOADS

WrongCat	&WrongCat::operator=(WrongCat &og)
{
	//std::cout << "Cat assignement operator called" << std::endl;
	this->_type = og.getType();
	return (*this);
}

//METHODS

void	WrongCat::makeSound(void) const
{
	std::cout << "Marrameu" << std::endl;
}

//DESTRUCTORS

WrongCat::~WrongCat(void)
{
	std::cout << "The wrong cat has been killed" << std::endl;
}
