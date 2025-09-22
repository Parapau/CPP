/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:53:33 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 20:27:26 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string		_type;
	private:
		Brain			*_brain;
	public:
		Animal(void);
		Animal(Animal &og);
		Animal	&operator=(Animal &og);
		virtual				~Animal(void);

		std::string			getType(void) const;
		Brain				*getBrain(void);
		void				setType(const std::string type);
		void				setBrain(Brain *brain);

		virtual void		makeSound(void) const;
};

#endif
