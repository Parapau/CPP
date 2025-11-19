/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:20:15 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/19 15:50:09 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat		a;
	Bureaucrat		b(1);
	Bureaucrat		c("Agapito Disousa", 42);

	std::cout << c << std::endl;
	c.downgrade();
	std::cout << c << std::endl;
	c.upgrade();
	c.upgrade();
	std::cout << c << std::endl;
	try
	{
		Bureaucrat		d(420);
	}
	catch (const std::exception & e)
	{
		std::cout << "Caught the following Exception: " << e.what()  << std::endl;
	}
	try
	{
		std::cout << b << std::endl;
		b.upgrade();
	}
	catch (const std::exception & e)
	{
		std::cout << "Caught the following Exception: " << e.what()  << std::endl;
	}
	try
	{
		std::cout << a << std::endl;
		a.downgrade();
	}
	catch (const std::exception & e)
	{
		std::cout << "Caught the following Exception: " << e.what()  << std::endl;
	}
	try
	{
		Bureaucrat		e(0);
	}
	catch (const std::exception & e)
	{
		std::cout << "Caught the following Exception: " << e.what() << std:: endl;
	}
}
