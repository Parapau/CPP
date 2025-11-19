/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:20:15 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/19 18:42:56 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat		a("Agapito Disousa", 42);
	Form			b("Crear la batamanta", 45, 55);
	Form			c("Coneixer a l'anselmo", 4, 5);

	try
	{
		Form d("Ninjas en patinets", 180, 3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Form d("Ninjas en patinets", 18, 300);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Form d("Ninjas en patinets", 180, 3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Form d("Ninjas en patinets", 80, -3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		a.signForm(b);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		a.signForm(c);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}
