/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:28:38 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 20:39:17 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Brain.hpp"

//CONSTRUCTOR

Brain::Brain(void)
{
	std::cout << "BRRRRRAAAAAAIIIINS" << std::endl;
	think("no thoughts, empty head");
}

Brain::Brain(const std::string thought)
{
	std::cout << "BRRRRRAAAAAAIIIINS" << std::endl;
	think(thought);
}

Brain::Brain(const Brain &og)
{
	std::cout << "BRRRRRAAAAAAIIIINS(copy)" << std::endl;
	for (int i = 0; i < 100; i++)
		setThought(og.getThought(i), i);
}

//OVERLOADS

Brain	&Brain::operator=(const Brain &og)
{
	for (int i = 0; i < 100; i++)
		setThought(og.getThought(i), i);
	return (*this);
}

//DESTRUCTORS

Brain::~Brain(void)
{
	std::cout << "🤯" << std::endl;
}

//METHODS

void	Brain::think(std::string thought)
{
	for (int i = 0; i < 100; i++)
		setThought(thought, i);
}

void	Brain::thinkOutLoud(void)
{
	std::cout << std::endl << "You shall give me a penny for my thoughts" << std::endl << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << getThought(i) << std::endl;
	std::cout << std::endl << "Now where's that penny" << std::endl << std::endl;
}


//GETTERS

std::string	Brain::getThought(int n) const
{
	return (this->_thoughts[n]);
}

//SETTERS

void	Brain::setThought(std::string thought, int n)
{
	this->_thoughts[n] = thought;
}
