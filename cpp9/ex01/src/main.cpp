/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:29:46 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/24 14:52:52 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../RPN.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments";
		return (0);
	}
	try
	{
		std::cout << rotaluklak::kurwa(argv[1]) << std::endl;;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
