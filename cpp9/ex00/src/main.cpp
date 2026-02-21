/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:11 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/21 12:05:20 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

int		main(int argc, char **argv)
{
	BitcoinExchange		CryptoBrosAreCringe;
	std::string			input;

	if (argc != 2)
	{
		std::cout << "puta";
		return (0);
	}
	std::cout << "openationing" << std::endl;
	input = argv[1];
	input = "../" + input;
	CryptoBrosAreCringe.doYourThing(input);
}
