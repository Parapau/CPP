/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:41:36 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/10 13:30:47 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_hPP
# define AFORM_hPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;
	public:
		Form(void);
		Form(Form &og);
		Form(std::string name);
		Form(std::string name, int signGrade, int execGrade);
		Form	&operator=(Form &og);
		virtual			~Form(void);

		std::string		getName(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		bool			getIsSigned(void);

		void			beSigned(Bureaucrat &bar);
		void			execute(Bureaucrat &bar);
		virtual void	carryOut(Bureaucrat &bar);
};

#endif
