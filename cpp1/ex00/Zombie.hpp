/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:07:13 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 19:48:50 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


#include <iostream>
#include <string>
#include <stdlib.h>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(void);
		~Zombie(void);
		std::string	getName(void) const;
		void		setName(std::string name);
		void		announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
	
#endif
