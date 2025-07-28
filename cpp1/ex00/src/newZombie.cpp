/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:25:51 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 18:55:59 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie;
	if (!zombie)
		exit(0);
	zombie->setName(name);
	return (zombie);
}
