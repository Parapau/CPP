/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:05:25 by pafranco          #+#    #+#             */
/*   Updated: 2025/08/06 11:18:33 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;

}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType()
		<< std::endl;
}

std::string HumanB::getName(void)
{
	return (this->_name);
}

Weapon *HumanB::getWeapon(void)
{
	return (this->_weapon);
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
