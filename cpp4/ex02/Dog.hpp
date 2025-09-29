/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:07:22 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/29 18:42:09 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"

class Dog: virtual public Animal
{
	public:
		Dog(void);
		Dog(Dog &og);
		Dog	&operator=(Dog &og);
		~Dog(void);

		void	makeSound(void) const;
};

#endif
