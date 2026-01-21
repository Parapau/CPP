/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:47:27 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/21 12:09:42 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string		str;
};

class Serializer
{
	private:
		Serializer(void);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deSerialize(uintptr_t);
};

#endif
