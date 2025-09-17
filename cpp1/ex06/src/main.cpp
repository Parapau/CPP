/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:59:34 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/15 17:29:55 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Harl.hpp"

int	main(int argc, char **argv)
{
	int				i;
	Harl			harl;
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (0);
	}
	harl = Harl();
	if (!(levels[0] == argv[1] || levels[2] == argv[1] || levels[3] == argv[1]
				|| levels[1] == argv[1]))
	{
		std::cout << "[Nothing important was said, as per usual]" << std::endl;
		return (0);
	}
	i = -1;
	switch(argv[1][0])
	{
		case ('D'):
			i = 0;
			break;
		case ('I'):
			i = 1;
			break;
		case ('W'):
			i = 2;
			break;
		case ('E'):
			i = 3;
			break;
		default:
			std::cout << "[Nothing important was said, as per usual]" << std::endl;
	}
	while (i < 4)
	{
		std::cout << '[' << levels[i] << ']' << std::endl;
		harl.complain(levels[i]);
		std::cout << std::endl;
		i++;
	}
}
