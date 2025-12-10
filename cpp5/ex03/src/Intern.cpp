/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:04:04 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/10 15:42:05 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Intern.hpp"

//CONSTRUCTORS

Intern::Intern(void)
{
}

Intern::Intern(Intern &og)
{
	*this = og;
}

//DESTRUCTORS

Intern::~Intern(void)
{
}

//OVERLOADS

Intern		&Intern::operator=(Intern &og)
{
	return (*this);
}

//METHODS

Form		*Intern::makeForm(std::string name, std::string target)
{
	std::string		forms[3] = {"PresidentialPardon", "ShrubberyCreationForm", "RobotomyRequest"};
	int				i;

	i = 0;
	while (i < 3 && name == forms[i])
		i++;
	switch (i)
	{
		case 0:
			return (new PresidentialPardon(target));
		case 1:
			return (new ShrubberyCreationForm(target));
		case 2:
			return (new RobotomyRequest(target));
	}
	std::cout << "No such form exists, this intern will be fired because you don't know your forms."
		<< std::endl << "Their career is over and it's your fault, you should be ashamed" << std:: endl;
	return (0);
}
