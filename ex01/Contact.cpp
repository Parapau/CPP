/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:21:51 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/11 12:26:58 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::printContact(void)
{
	std::cout << getFName() << std::endl;
	std::cout << getSName() << std::endl;
	std::cout << getNick() << std::endl;
	std::cout << getNum() << std::endl;
	std::cout << getSecret() << std::endl;
}

std::string	Contact::getFName(void) const
{
	return (this->_fName);
}

std::string	Contact::getSName(void) const
{
	return (this->_sName);
}

std::string	Contact::getNick(void) const
{
	return (this->_nick);
}

std::string	Contact::getNum(void) const
{
	return (this->_num);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}

void	Contact::setFName(std::string fName)
{
	this->_fName = fName;
}

void	Contact::setSName(std::string sName)
{
	this->_sName = sName;
}

void	Contact::setNick(std::string nick)
{
	this->_nick = nick;
}

void	Contact::setNum(std::string num)
{
	this->_num = num;
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}
