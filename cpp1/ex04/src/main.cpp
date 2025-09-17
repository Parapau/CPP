/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:12:46 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/15 18:40:59 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

static std::string	checkWord(std::string line, std::string oldW, std::string newW)
{
	size_t				i;
	int				start;
	int				len;
	std::string		newLine;

	len = oldW.length();
	start = 0;
	newLine = "";
	i = line.find(oldW, 0);
	while (i != std::string::npos)
	{
		newLine.append(line, start, (int)i - start);
		newLine.append(newW);
		start = (int)i + len;
		i = line.find(oldW, start);
	}
	if (start == 0)
		newLine = line;
	else
		newLine.append(line, start, i);
	return (newLine);
}

int	main(int argc, char **argv)
{
	std::string		line;
	std::string		text;
	std::string		file;

	text = "";
	if (argc != 4)
	{
		std::cout << "Wrong numbers of arguments";
		return (1);
	}
	file = argv[1];
	std::ifstream inFile(argv[1]);
	while (std::getline(inFile, line))
	{
		text.append(checkWord(line, argv[2], argv[3]));
		text.append("\n");
	}
	inFile.close();
	file.append(".replace");
	std::ofstream outfile(file.c_str());
	outfile << text;
	outfile.close();
}
