/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:37:16 by pafranco          #+#    #+#             */
/*   Updated: 2025/10/28 15:37:50 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Bureaucrat.hpp"

//CONSTRUCTORS

Bureaucrat::Bureaucrat(void)
{
//	std::cout << "Basic Bureaucrat created" << std::endl;
	setName("Basic Bitch");
	setGrade(150);
}

Bureaucrat::Bureaucrat(Bureaucrat &og)
{
	*this = og;
}

Bureaucrat::Bureaucrat(int grade)
{
//	std::cout << "Graded Bureaucrat created" << std::endl;
	setName("Classy Bitch");
	setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
//	std::cout << "Named Bureaucrat created" << std::endl;
	setName(name);
	setGrade(grade);
}

//DESTRUCTORS

Bureaucrat::~Bureaucrat(void)
{
//	std::cout << "I can't think of anything witty to say" << std::endl;
}

//OVERLOADS

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &og)
{
	o << "Hi, my name is " << og.getName() << " and i'm a grade "
		<< og.getGrade() << " Bureaucrat and i hate my job :(";
	return (o);
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &og)
{
	setName(og.getName());
	setGrade(og.getGrade());
	return (*this);
}

//GETTERS

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//SETTERS

void	Bureaucrat::setName(std::string name)
{
	this->_name = name;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());//grade));
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());//grade));
	this->_grade = grade;
}

//METHODS

void	Bureaucrat::upgrade(void)
{
	int		grade;

	grade = getGrade();
	if (grade <= 1)
		throw (Bureaucrat::GradeTooHighException());//grade - (grade == 1)));
	setGrade(grade - 1);
}

void	Bureaucrat::downgrade(void)
{
	int		grade;

	grade = getGrade();
	if (grade >= 150)
		throw (Bureaucrat::GradeTooLowException());//grade + (grade == 150)));
	setGrade(grade + 1);
}

//EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{/*
	std::string		message;
	const char			*ret;

	message = "Grade " + this->_grade + " is too high, you fucking idiot";
	ret = message.c_str();
	return (ret);*/
	return ("This grade is too high you fuckking idiot");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{/*
	std::string		message;
	const char			*ret;

	message = "Grade " + this->_grade + " is too low, you fucking idiot";
	ret = message.c_str();
	return (ret)*/;
	return ("This grade is too low you fuckking idiot");
}
