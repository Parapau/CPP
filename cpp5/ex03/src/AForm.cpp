/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:19:05 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/10 14:11:11 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm.hpp"

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

void	Form::execute(Bureaucrat &bar)
{
	if (bar.getGrade() >= getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	if (getIsSigned() != 1)
		throw (Bureaucrat::FormNotSignedException());
	this->carryOut(bar);
}

void	Form::carryOut(Bureaucrat &bar)
{
		std::cout << "Se que cada qual tiene su aficion, yo cazo para elaborar un verstuario resulton." << std::endl
		<< "Y lo ven, ya lo ven. EL gorila sienta bien. Mi chaqueta no se agrieta es de autentica gineta. " << std::endl
		<< "Este es mi siames. Imagen doy de marques. En la casa me engalano con estilo africano. " << std::endl
		<< "Un calzon de bison. Un jersey caparazon. Oportuno fez perruno en la sieeen. Abrigos de plumon, los hay de quita y pon. ;" << std::endl
		<< "Ya lo ven, ya lo ven, ya lo veeeeen" << std::endl
		<< "Mooocasines saltarines con la piel de dos mastines. Los cachorros para esmoquin van feteeen." << std::endl
		<< "Pues bien preparalos." << std::endl << "Y casi salen dos." << std::endl
		<< "Ya lo ven, ya lo veen, oh si yo lo se muy bieeeeeeeeeeeeeeeen" << std::endl
		<< "Me encanta esta prenda" << std::endl
		<< "Ya me he dado cuenta" << std::endl
		<< "Oohhh, esta pensando hacerse un esmoquin con los cachorros!" << std::endl
		<< "Nanana, nanana, nananana." << std::endl
		<< bar.getName() << std::endl;

}
