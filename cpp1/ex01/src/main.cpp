/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:52:26 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 19:18:20 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		i;

	i = 0;
	horde = zombieHorde(5 ,"Agapito Disousa");
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}
