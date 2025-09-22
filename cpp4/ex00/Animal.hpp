/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:53:33 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:42:01 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string		_type;
	public:
		Animal(void);
		Animal(Animal &og);
		Animal	&operator=(Animal &og);
		virtual				~Animal(void);

		std::string			getType(void) const;
		void				setType(const std::string type);

		virtual void		makeSound(void) const;
};

#endif
