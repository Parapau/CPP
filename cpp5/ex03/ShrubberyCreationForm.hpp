/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:57:50 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/10 13:51:46 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
	private:
		std::string		_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm &og);
		~ShrubberyCreationForm(void);

		std::string		getTarget(void);

		void			setTarget(std::string target);

		void			carryOut(Bureaucrat &bar);
};

#endif
