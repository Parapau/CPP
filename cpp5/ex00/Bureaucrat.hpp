/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:19:39 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/14 14:45:47 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	protected:
		std::string		_name;
		int				_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat &og);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat	&operator=(Bureaucrat &og);
		~Bureaucrat(void);

		std::string		getName(void) const;
		int				getGrade(void) const;

		void			setName(std::string name);
		void			setGrade(int grade);

		void			upgrade(void);
		void			downgrade(void);

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream  &os, Bureaucrat const &og);

#endif
