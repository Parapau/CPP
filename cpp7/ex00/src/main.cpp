/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:52:45 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/22 15:52:46 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Templates.hpp"
#include <string>
#include <iostream>

int main(void)
{
	std::string		s1;
	std::string		s2;
	int				i1;
	int				i2;

	i1 = 1;
	i2 = 2;
	s1 = "patata";
	s2 =  "fregida";
	std::cout << "i1 = " << i1 << std::endl
		<< "i2 = " << i2 << std::endl
		<< "s1 = " << s1 << std::endl
		<< "s2 = " << s2 << std::endl << std::endl
		<< "max i1/i2 = " << myMax(i1, i2) << " min i1/i2 = " << myMin(i1, i2)
		<< std::endl << std::endl;
	mySwap(i1, i2);
	mySwap(s1, s2);
	std::cout << "i1 = " << i1 << std::endl
		<< "i2 = " << i2 << std::endl
		<< "s1 = " << s1 << std::endl
		<< "s2 = " << s2 << std::endl;
}
