/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:05:23 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:34:40 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	protected:
		std::string		type;
	public:
		WrongCat(void);
		WrongCat(WrongCat &og);
		WrongCat	&operator=(WrongCat &og);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
