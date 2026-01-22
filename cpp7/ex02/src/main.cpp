/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:25:41 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/22 15:59:37 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Array.hpp"

int	main(void)
{
	Array<std::string>		arr1(void);
	Array<std::string>		arr2(5);

	for (int i = 0 ; i < 5 ; i++)
		arr2[i] = "Gugridigugridigu";
	for (int i = 0 ; i < 5 ; i++)
		std:: cout << arr2[i] << i << std::endl;
	Array<std::string>		arr3(arr2);
	arr3[3] = "patata";
	std::cout << std::endl << std::endl;
	for (int i = 0 ; i < 5 ; i++)
		std:: cout << arr2[i] << i << std::endl;
	std::cout << std::endl << std::endl;
	for (int i = 0 ; i < 5 ; i++)
		std:: cout << arr3[i] << i << std::endl;
	
	try
	{
		arr2[420] = "patata";
	}
	catch (std::exception & e)
	{
		std::cout << "index out of bounds for array" << std::endl;
	}
}
