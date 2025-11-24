/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:57:50 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/24 20:33:15 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

#include "AForm.hpp"

class PresidentialPardon: public Form
{
	private:
		std::string		_target;
	public:
		PresidentialPardon(void);
		PresidentialPardon(std::string target);
		PresidentialPardon	&operator=(PresidentialPardon &og);
		~PresidentialPardon(void);

		std::string		getTarget(void);

		void			setTarget(std::string target);

		void			execute(Bureaucrat &bar);
};

#endif
