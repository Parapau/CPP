/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:05 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/23 19:19:41 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AAnimal.hpp"
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
	Animal		*Maya = new Cat();
	Animal		*Mixa;

	Maya->getBrain()->thinkOutLoud();
	Maya->getBrain()->think("I'm not a cat i'm, i'm a cattopotamus");
	Maya->getBrain()->setThought("Hmmmm, if i don't get inside this box this instant i will die", 3);
	Maya->getBrain()->thinkOutLoud();
	Mixa = Maya;
	Mixa->getBrain()->thinkOutLoud();

	delete Maya;
}

void bstract(void)
{
//	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
//	meta->makeSound();

	delete i;
	delete j;
//	delete meta;
}

int	main(int argc, char **argv)
{
	if (argv == (char **) &argc)
		std::cout << "goddamned unused variables warning" << std::endl;
	if (argc == 0)
	{
		catBook();
		a();
	}
	else
		bstract();
	return (0);
}
