/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:49:42 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 21:01:39 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUAMANB_HPP
# define HUAMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		std::string	getName(void);
		Weapon		*getWeapon(void);
		void		setName(std::string name);
		void		setWeapon(Weapon &weapon);
		void		attack(void);
};

#endif
