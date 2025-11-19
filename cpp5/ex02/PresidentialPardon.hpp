/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:57:50 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/19 19:09:23 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

#include "AForm.hpp"

class PresidentialPardon: public AMateria
{
	private:
		std::string		targert;
	public:
		PresidentialPardon(void);
		PresidentialPardon(std::string target);
		~PresidentialPardon(void);

	
}

#endif
