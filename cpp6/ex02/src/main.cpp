/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:31:20 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/19 13:21:28 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <time.h>
#include "../Classes.hpp"

Base	*generate(void)
{

	Base	*ptr;

	switch(rand() % 3)
	{
		case (0):
			ptr = new A();
			break;
		case(1):
			ptr = new B();
			break;
		case(2):
			ptr = new C();
			break;
	}
	return (ptr);
}

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a != 0)
	{
		std::cout << "This object is of A class" << std::endl
			<< "(not a as in the article a, A as in the class A)" << std::endl;
	}
	else if (b != 0)
	{
		std::cout << "This object is of B class" << std::endl
			<< "(not being elitist just their name)" << std::endl;
	}
	else if (c != 0)
	{
		std::cout << "This object is of C class" << std::endl
			<< "(not sea class you idiot, C class you c)" << std::endl;
	}
	else
		std::cout << "The programer is a fucking moron" << std::endl;
}

void	identify(Base &p)
{
	A		a;
	B		b;
	C		c;
	int		type;

	type = 0;
	try
	{
		a = dynamic_cast<A&>(p);
	}
	catch (const std::exception &e)
	{
		type += 1;
	}
	try
	{
		b = dynamic_cast<B&>(p);
	}
	catch (const std::exception &e)
	{
		type += 2;
	}
	try
	{
		c = dynamic_cast<C&>(p);
	}
	catch (const std::exception &e)
	{
		type += 3;
	}
	switch (type)
	{
		case 3:
			std::cout << "This object is of C class" << std::endl
				<< "(not sea class you idiot, C class you c)" << std::endl;
			break;
		case 4:
			std::cout << "This object is of B class" << std::endl
				<< "(not being elitist just their name)" << std::endl;
			break;
		case 5:
			std::cout << "This object is of A class" << std::endl
				<< "(not a as in the article a, A as in the class A)" << std::endl;
			break;
		default:
			std::cout << "The programer is a fucking moron " << type << std::endl;
			break;
	}
}

int	main(void)
{
	srand(time(0));
	identify(generate());
	std::cout << std::endl << std::endl;
	identify(*generate());
}
