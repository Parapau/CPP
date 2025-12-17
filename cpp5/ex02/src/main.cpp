/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:20:15 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/17 17:06:07 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"
#include "../PresidentialPardon.hpp"
#include "../ShrubberyCreationForm.hpp"
#include "../RobotomyRequest.hpp"

int	main(void)
{
	Bureaucrat				a("Agapito Disousa", 2);
	Bureaucrat				b("Mariano Aznar", 150);
	PresidentialPardon		ogro("el xaval");
	RobotomyRequest			doraemon("la germana del doraemon");
	ShrubberyCreationForm	shrub("monke");

	try
	{
		a.signForm(shrub);
		a.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		a.signForm(doraemon);
		a.executeForm(doraemon);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		a.signForm(ogro);
		a.executeForm(ogro);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		b.signForm(shrub);
		b.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		b.signForm(doraemon);
		b.executeForm(doraemon);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		b.signForm(ogro);
		b.executeForm(ogro);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
