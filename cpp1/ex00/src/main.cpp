/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:52:26 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 18:57:00 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Agapito Disousa");
	zombie->Zombie::announce();
	randomChump("Anselmo");
	zombie->Zombie::~Zombie();
}
