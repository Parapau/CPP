/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:05:23 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/29 18:41:48 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: virtual public Animal
{
	public:
		Cat(void);
		Cat(Cat &og);
		Cat	&operator=(Cat &og);
		~Cat(void);

		void	makeSound(void) const;
};

#endif
