/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:53:33 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 17:48:14 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string		_type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &og);
		WrongAnimal	&operator=(WrongAnimal &og);
		virtual			~WrongAnimal(void);

		std::string		getType(void) const;
		void					setType(const std::string type);

		void		makeSound(void) const;
};

#endif
