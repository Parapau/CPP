/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:12:46 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/29 18:34:51 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	checkWord(std::ifstream in)
{
}

int	main()
{
	std::string		text;
	std::string		fin;

	std::ifstream MyFile("a.txt");
	while (std::getline(MyFile, text))
	{
		std::cout << text << std::endl;
		fin << text << std::endl;
	}
	MyFile.close();
}
