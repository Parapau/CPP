/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:39:30 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/09 16:02:26 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			contacts[8];
		int				newest;
		int				checkIndex(int newest);
		void			addToArray(Contact contact);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void			add(void);//Contact contact);
		void			search(void);
		Contact			*getContacts(void);
		int				getNewest(void);
		void			setContacts(Contact *contacts);
		void			setNewest(int newest);
};

#endif
