/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:08:45 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/23 19:16:18 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AAnimal.hpp"

//CONSTRUCTORS

Animal::Animal(void)
{
	std::cout << "Animal base constructor called" << std::endl;
	this->_type = "Gambusino";
}

Animal::Animal(Animal &og)
{
	std::cout << "Animal copy constructor called" << std::endl;
	setBrain(new Brain(*og.getBrain()));
	this->_type = og.getType();
}

//OVERLOADS

Animal	&Animal::operator=(Animal &og)
{
	std::cout << "Animal assignement overload called" << std::endl;
	this->_type = og.getType();
	setBrain(new Brain(*og.getBrain()));
	return (*this);
}

//GETTERS

std::string	Animal::getType(void) const
{
	return (this->_type);
}

Brain	*Animal::getBrain(void)
{
	return (this->_brain);
}

//SETTERS

void	Animal::setType(const std::string type)
{
	this->_type = type;
}

void	Animal::setBrain(Brain *brain)
{
	this->_brain = brain;
}

//METHODS

//void	Animal::makeSound(void) const
//{
//	std::cout << "AAJJHSJFHSJDFLKDJBNSDJHGPAEFAJBRGAJDFGLKJDSJBLKJSDFGPJJF" << std::endl;
//}

//DESTRUCTORS

Animal::~Animal(void)//the animal destroys the brain therefore it makes sense that the brain is the last thing to output since the destructor is only saying it has been called
{
	std::cout << "Animal destructor called" << std::endl;
	delete this->_brain;
}
