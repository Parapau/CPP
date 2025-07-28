/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:07:13 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 20:01:47 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


#include <iostream>
#include <string>
#include <stdlib.h>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string	getType(void) const;
		void		setType(std::string type);
};

#endif
