/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:19:05 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/19 18:33:00 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Form.hpp"

//CONSTRUCTORS

Form::Form(void):
	_signGrade(4), _execGrade(20), _isSigned(0)
{
}

Form::Form(Form &og):
	_name(og._name), _signGrade(og._signGrade), _execGrade(og._execGrade),
	_isSigned(og._isSigned)
{
}

Form::Form(std::string name):
	_name(name), _signGrade(4), _execGrade(20), _isSigned(0)
{
}


Form::Form(std::string name, int signGrade, int execGrade):
	_name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(0)
{
	if (execGrade > 150 || signGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (execGrade < 1 || signGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Form	&Form::operator=(Form &og)
{
	_isSigned = og._isSigned;
	return (*this);
}

//DESTRUCTORS

Form::~Form(void)
{
}

//GETTERS

std::string		Form::getName(void) const
{
	return (this->_name);
}

int		Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int		Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	Form::getIsSigned(void)
{
	return (this->_isSigned);
}

//METHODS

void	Form::beSigned(Bureaucrat &bar)
{
	if (bar.getGrade() >= getSignGrade())
		throw (Bureaucrat::GradeTooLowException());
	this->_isSigned = 1;
}




