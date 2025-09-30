/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:05 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/30 16:29:18 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Animal.hpp"
#include "../Cat.hpp"
#include "../Dog.hpp"
#include "../Brain.hpp"

void	catBook(void)
{
	Animal*		animals[10];

	for (int i = 0; i < 10; i += 2)
	{
		animals[i] = new Dog();
		animals[i + 1] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
}

void	a(void)
{
	Cat		Maya;

	Maya.getBrain()->thinkOutLoud();
	Maya.getBrain()->think("I'm not a cat i'm, i'm a cattopotamus");
	Maya.getBrain()->setThought("Hmmmm, if i don't get inside this box this instant i will die", 3);
	Maya.getBrain()->thinkOutLoud();
	Cat Mixa = Maya;
	Mixa.getBrain()->thinkOutLoud();
}

int	main(int argc, char **argv)
{
	if (argv == (char **) &argc)
		std::cout << "goddamned unused variables warning" << std::endl;
	if (argc == 1)
		catBook();
	else
		a();
	return (0);
}
