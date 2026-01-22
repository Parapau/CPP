/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:25:41 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/22 15:41:00 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Array.hpp"

int	main(void)
{
	Array<std::string>		arr1(void);
	Array<std::string>		arr2(5);

	for (int i = 0 ; i < 5 ; i++)
		arr2[i] = "puta";
	for (int i = 0 ; i < 5 ; i++)
		std:: cout << arr2[i] << i << std::endl;
	try
	{
		arr2[420] = "patata";
	}
	catch (std::exception & e)
	{
		std::cout << "index out of bounds for array" << std::endl;
	}
}
