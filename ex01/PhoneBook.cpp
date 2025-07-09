/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:39:23 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/09 16:09:52 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->newest = 0;
}

PhoneBook::~PhoneBook(void)
{
}

static void	print10(std::string print)
{
	int		len;

	len = print.length();
	if (len > 10)
		std::cout << print.substr(0, 9) << ".";
	else
		std::cout << std::setw(10 - len)  << print;
}

static int	parseIndex(std::string input, int newest)
{
	int		index;

	if (input[0] > '8' || input[0] < '1' || input[1] != 0 )
		return(-1);
	index = input[0] - '0' + newest;
	if (index < 0)
		index += 8;
	return (index);
}

static int	checkEmpty(Contact contact)
{
	if(contact.getFName().empty() || contact.getSName().empty() || contact.getNick().empty()
		|| contact.getNum().empty() || contact.getSecret().empty())
	{
		std::cout << "estic mes buit que el teu cap subnormal" << std::endl;
		return(1);
	}
	return(0);
}

int	PhoneBook::checkIndex(int newest)
{
	std::string		input;
	int				index;

	index = 0;
	while (index <= 0)
	{
		std::cout << "Give me the index of the Contact you wish to view:";
		std::cin >> input;
		index = parseIndex(input, newest);
		if (index == -1)
			std::cout << "That's not a correct index stupid" << std::endl;
		index = 0;
		input = "";
	}
	return (index);
}

void	PhoneBook::addToArray(Contact contact)
{
	this->contacts[getNewest()] = contact;
//	std::cout << getNewest();
	setNewest(getNewest() + 1);
//	std::cout << getNewest();
	if (getNewest() == 8)
		setNewest(0);
}

void	PhoneBook::add(void)//Contact contact)
{
	Contact contact;
	std::string		input;

	while(checkEmpty(contact))
	{
		if (!input.empty())
			std::cout << "none of the fields may be empty, please fill them again" << std::endl;
		std::cout << "Introduce the new contact's first name:" << std::endl;
		std::cin >> input;
		contact.setFName(input);
		std::cout << "Introduce the new contact's surname:" << std::endl;
		std::cin >> input;
		contact.setSName(input);
		std::cout << "Introduce the nickanme of this new contact:" << std::endl;
		std::cin >> input;
		contact.setNick(input);
		std::cout << "Introduce the new contact's number:" << std::endl;
		std::cin >> input;
		contact.setNum(input);
		std::cout << "Share with me this contact's juiciest and darkest secret >:) :" << std::endl;
		std::cin >> input;
		contact.setSecret(input);
	}
	addToArray(contact);
	std::cout << getNewest();
}

void	PhoneBook::search(void)
{
	int		i;
	int		n;
	int		index;

	i = getNewest() - 1;
	if (i < 0)
		i = 8;
	n = i;
	index = 1;
	getContacts()[0].printContact();
	while (index == 1 || checkEmpty(getContacts()[0]))
	{
		std::cout << "JODERRRRRRRR" << std::setw(9) << '0' + index << "|";
		print10(getContacts()[0].getFName());
		std::cout << "|";
		print10(getContacts()[0].getSName());
		std::cout << "|";
		print10(getContacts()[0].getNick());
		std::cout << std::endl;
		index++;
		if (i == 0)
			i = 8;
		i--;
	}
	index = checkIndex(getNewest());
	if (checkEmpty(getContacts()[index]))
	{
		std::cout << "That contact doesn't exist yet, you should create it :)" << std::endl;
		return ;
	}
	getContacts()[index].printContact();
}

Contact	*PhoneBook::getContacts(void)
{
	return (this->contacts);
}

int	PhoneBook::getNewest(void)
{
	return (this->newest);
}

void	PhoneBook::setNewest(int newest)
{
	this->newest = newest;
}
