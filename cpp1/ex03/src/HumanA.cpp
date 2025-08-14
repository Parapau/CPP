/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:05:25 by pafranco          #+#    #+#             */
/*   Updated: 2025/08/06 11:18:51 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType()
		<< std::endl;
}

std::string HumanA::getName(void)
{
	return (this->_name);
}

Weapon *HumanA::getWeapon(void)
{
	return (this->_weapon);
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
