/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:20:15 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/10 13:50:13 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"
#include "../PresidentialPardon.hpp"
#include "../ShrubberyCreationForm.hpp"
#include "../RobotomyRequest.hpp"

int	main(void)
{
	Bureaucrat				a("Agapito Disousa", 2);
	PresidentialPardon		ogro("el xaval");
	RobotomyRequest			doraemon("la germana del doraemon");
	ShrubberyCreationForm	shrub("monke");

	a.signForm(shrub);
	a.executeForm(shrub);

	try
	{
		Form d("Ninjas en patinets", 180, 3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}
