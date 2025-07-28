/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:49:42 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 21:00:32 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUAMANA_HPP
# define HUAMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		std::string	getName(void);
		Weapon		*getWeapon(void);
		void		setName(std::string name);
		void		setWeapon(Weapon &weapon);
		void		attack(void);
};

#endif
