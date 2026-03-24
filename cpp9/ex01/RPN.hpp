/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:57:59 by pafranco          #+#    #+#             */
/*   Updated: 2026/03/24 14:43:50 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <list>
#include <cstdlib>
#include <sstream>
#include <iostream>

class rotaluklak// kalkulator in calculator in polish, and it's in reverse :)
{
	private:
		rotaluklak(void);
		~rotaluklak(void);

	public:
		static long long	kurwa(std::string);

	class Bad: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
