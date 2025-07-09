/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:48:22 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/09 15:38:01 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	booking(void)
{
	PhoneBook		book;
	std::string		say;
	int				done;

	done = 0;
	book = PhoneBook();
	std::cout << "Welcome to your digital phonebook" << std::endl;
	while (done == 0)
	{
		std::cout << "you can only ADD, SEARCH or EXIT, nothing else:" << std::endl;
		std::cin >> say;
		if (say.std::string::compare(0, 4, "ADD", 0, 4) == 0)
			book.add();//book.getContacts()[book.getNewest()]);
		if (say.std::string::compare(0, 7, "SEARCH", 0, 7) == 0)
			book.search();
		if (say.std::string::compare(0, 5, "EXIT", 0, 5) == 0)
			done = 1;
		say = "";
	}
}

int	main(void)
{
	booking();
}
