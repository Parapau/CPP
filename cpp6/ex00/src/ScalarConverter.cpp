/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:03:23 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/12 15:47:00 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScalarConverter.hpp"
#include <limits.h>
#include <stdlib.h>
#include <float.h>

//FUNCTIONS

void	print(char c, int i, float f, double d, std::string input)
{
	(void) input;
	std::cout << "CHAR: ";
	if (isprint(c))
		std::cout << '\'' << c << '\'' << std::endl;
	else
		std::cout << "Non printable" << std::endl;
	std::cout << "INT: ";
	if (d > INT_MIN || d < INT_MAX)
		std::cout << i << std::endl;
	else if (d > INT_MAX)
		std::cout << "Overflow" << std::endl;
	else
		std::cout << "Underflow" << std::endl;
	std::cout << "FLOAT: ";
	if (d > FLT_MIN || d < FLT_MAX)
	{
		std::cout << f ;
		//putDecimals(input, 1);
		std::cout << 'f' << std::endl;
	}
	else if (d > FLT_MAX)
		std::cout << "Overflow" << std::endl;
	else
		std::cout << "Underflow" << std::endl;
	std::cout << "DOUBLE: " << d;
	//putDecimals(input, 2);
	std::cout << std::endl;
}

void	print2(std::string input, int type)
{
	std::cout << "CHAR: Impossible" << std::endl;
	std::cout << "INT: Impossible" << std::endl;
	std::cout << "FLOAT: " << input;
	if (type == spd)
		std::cout << 'f';
	std::cout << std::endl;
	std::cout << "DOUBLE: ";
	if (type == spf)
		*(input.end() - 1) = 0;
	std::cout << input << std::endl;

}

Type	typeDetector(std::string input)
{
	int								j;
	std::string						specials[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	std::string::const_iterator		i;

	j = 0;
	i = input.begin();
	if (input.size() == 1)
	{
		if (isdigit(*i))
			return (in);
		else
			return (ch);
	}
	if (*i == '-' || *i == '+')
		i++;
	while (i != input.end() && (isdigit(*i)))
		i++;
	if (i == input.end())
		return (in);
	else if (*i == '.')
	{
		if (*(input.rbegin()) == 'f')
			return (fl);
		else
			return (db);
	}
	else
	{
		while (j < 6)
		{
			if (input == specials[j] && j < 3)
				return (spf);
			else if (input == specials[j])
				return (spd);
			j++;
		}
	}
	return (er);
}

//METHODS

void	ScalarConverter::convert(std::string input)
{
	int			type;
	char		c;
	int			i;
	float		f;
	double		d;

	c = 0;
	i = 0;
	d = 0;
	f = 0;
	type = typeDetector(input);
	switch(type)
	{
		case 0:
			c = input[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case 1:
			i = (std::atoi(input.c_str()));
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case 2:
			f = (std::atof(input.c_str()));
			i = static_cast<int>(f);
			c = static_cast<char>(f);
			d = static_cast<double>(f);
			break ;
		case 3:
			d = (std::atof(input.c_str()));
			i = static_cast<int>(d);
			c = static_cast<char>(d);
			f = static_cast<float>(d);
			break ;
		case 4:
			print2(input, type);
			return ;
		case 5:
			print2(input, type);
			return ;
		default:
			std::cout << input <<" If you see me, weep " << type << std::endl;	
	}
	print(c, i, f, d, input);
}
