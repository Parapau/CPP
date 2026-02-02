/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:08:33 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/02 16:19:37 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class	ElementNotFound: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Element not found");
		}
};

template <typename T>
int	easyfind(T &cont, int n)
{
	typename	T::iterator elem;

	elem = find(cont.begin(), cont.end(), n);
	if (elem == cont.end())
		throw (ElementNotFound());
	return (*elem);
}


#endif
