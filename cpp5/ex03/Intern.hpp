/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:58:58 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:43 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequest.hpp"
#include "PresidentialPardon.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern &og);
		Intern &operator=(Intern &og);
		~Intern(void);

		Form	*makeForm(std::string name, std::string target) const;

	class NoSuchFormException: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif
