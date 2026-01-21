/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:13:52 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/21 12:02:49 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Serializer.hpp"

int	main(void)
{
	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	data.str = "Gugridigugridigu";
	raw = Serializer::serialize(&data);
	ptr = Serializer::deSerialize(raw);
	std::cout << ptr->str << std::endl;
}
