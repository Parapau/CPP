/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:58:38 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/12 16:33:32 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Serializer.hpp"

uintptr_t		Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deSerialize(uintptr_t ser)
{
	return (reinterpret_cast<Data *>(ser));
}
