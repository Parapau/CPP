/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:57:24 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/09 14:49:33 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	_fName;
		std::string	_sName;
		std::string	_nick;
		std::string	_num;
		std::string	_secret;
	public:
		Contact(void);
		Contact(std::string fName, std::string sName, std::string mick
			, std::string num, std::string secret);
		~Contact(void);
		void		printContact(void);
		std::string	getFName(void) const;
		std::string	getSName(void) const;
		std::string	getNick(void) const;
		std::string	getNum(void) const;
		std::string	getSecret(void) const;
		void		setFName(std::string);
		void		setSName(std::string);
		void		setNick(std::string);
		void		setNum(std::string);
		void		setSecret(std::string);
};

#endif
