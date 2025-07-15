/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:39:23 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/15 18:53:49 by tv               ###   ########.fr       */
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
		std::cout << std::setw(10)  << print;
}

static int	checkEmpty(Contact contact)
{
	if(contact.getFName().empty() || contact.getSName().empty() || contact.getNick().empty()
		|| contact.getNum().empty() || contact.getSecret().empty())
		return(1);
	return(0);
}

void	PhoneBook::addToArray(Contact contact)
{
	this->contacts[getNewest()] = contact;
	setNewest(getNewest() + 1);
	if (getNewest() == 8)
		setNewest(0);
}

void	PhoneBook::add(void)
{
	Contact contact;
	std::string		input;

	while(checkEmpty(contact))
	{
		if (!input.empty())
			std::cout << "none of the fields may be empty, please fill them again" << std::endl;
		std::cout << "Introduce the new contact's first name:" << std::endl;
		std::getline(std::cin, input);
		contact.setFName(input);
		input = "";
		std::cout << "Introduce the new contact's surname:" << std::endl;
		std::getline(std::cin, input);
		contact.setSName(input);
		input = "";
		std::cout << "Introduce the nickanme of this new contact:" << std::endl;
		std::getline(std::cin, input);
		contact.setNick(input);
		input = "";
		std::cout << "Introduce the new contact's number:" << std::endl;
		std::getline(std::cin, input);
		contact.setNum(input);
		input = "";
		std::cout << "Share with me this contact's juiciest and darkest secret >:) :" << std::endl;
		std::getline(std::cin, input);
		contact.setSecret(input);
	}
	addToArray(contact);
	std::cout << getNewest();
}

static int	parseIndex(std::string input, int newest)
{
	int		index;

	if (input[0] > '8' || input[0] < '1' || input[1] != 0 )
		return(-1);
	index = newest - (input[0] - '0');
	if (index < 0)
		index += 8;
	if (index > 7)
		index -= 8;
	return (index);
}

int	PhoneBook::checkIndex(int newest)
{
	std::string		input;
	int				index;

	index = -1;
	while (index < 0)
	{
		index = 0;
		std::cout << "Give me the index of the Contact you wish to view:";
		std::getline(std::cin, input);
		index = parseIndex(input, newest);
		if (index == -1)
			std::cout << "That's not a correct index stupid" << std::endl;
	}
	return (index);
}

void	PhoneBook::search(void)
{
	int		i;
	int		index;

	i = getNewest() - 1;
	if (i < 0)
		i = 7;
	index = 1;
	if (checkEmpty(getContacts()[0]))
	{
		std::cout << "The contact list is empty, please add a contact before searching for one" << std::endl;
		return ;
	}
	while ((i != getNewest() - (getNewest() != 0) + ((getNewest() == 0) * 7) || index == 1)
			&& !checkEmpty(getContacts()[i]))
	{
		std::cout << std::setw(10) << index << "|";
		print10(getContacts()[i].getFName());
		std::cout << "|";
		print10(getContacts()[i].getSName());
		std::cout << "|";;
  		print10(getContacts()[i].getNick());
		std::cout << std::endl;
		index++;
		if (i == 0)
			i = 8;
		i--;
	}
	index = checkIndex(getNewest());
	if (checkEmpty(getContacts()[index]))
	{
		std::cout << index << "That contact doesn't exist yet, you should create it :)" << std::endl;
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
