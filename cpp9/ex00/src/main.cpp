/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:11 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/20 15:31:54 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

int		main(int argc, char **argv)
{
	BitcoinExchange		CryptoBrosAreCringe;
	std::string			input;

	if (argc != 2)
		return (0);
	input = argv[1];
	input = "../" + input;
	CryptoBrosAreCringe.doYourThing(input);
}
