/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:41:36 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/19 19:04:25 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_hPP
# define FORM_hPP

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
};

#endif
