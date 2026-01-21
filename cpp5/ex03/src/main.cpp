/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:20:15 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/15 16:21:38 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"
#include "../PresidentialPardon.hpp"
#include "../ShrubberyCreationForm.hpp"
#include "../RobotomyRequest.hpp"
#include "../Intern.hpp"

int	main(void)
{
	Bureaucrat				a("Agapito Disousa", 2);
	Form					*ogro;
	Form					*doraemon;
	Form					*shrub;
	Form					*poropopo;
	Intern					becari;

	try
	{
		ogro = becari.makeForm("PresidentialPardon", "Izarra");
		a.signForm(*ogro);
		a.executeForm(*ogro);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		doraemon = becari.makeForm("RobotomyRequest", "La germana del doraemon");
		a.signForm(*doraemon);
		a.executeForm(*doraemon);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		shrub = becari.makeForm("ShrubberyCreationForm", "monke");
		a.signForm(*shrub);
		a.executeForm(*shrub);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		poropopo = becari.makeForm("PoropopoPero", "Poro");
		a.signForm(*poropopo);
		a.executeForm(*poropopo);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
