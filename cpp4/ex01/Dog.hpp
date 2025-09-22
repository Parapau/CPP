/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:07:22 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 20:31:28 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: virtual public Animal
{
	protected:
		std::string		type;
	public:
		Dog(void);
		Dog(Dog &og);
		Dog	&operator=(Dog &og);
		virtual ~Dog(void);

		void	makeSound(void) const;
};

#endif
