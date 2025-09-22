/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:05:23 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 20:31:39 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: virtual public Animal
{
	protected:
		std::string		type;
	public:
		Cat(void);
		Cat(Cat &og);
		Cat	&operator=(Cat &og);
		virtual ~Cat(void);

		void	makeSound(void) const;
};

#endif
