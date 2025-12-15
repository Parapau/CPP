/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:03:23 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/15 19:41:47 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScalarConverter.hpp"

//FUNCTIONS

void	print(char c, int i, float f, double d)
{
	std::cout << "CHAR: ";
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non printable" << std::endl;
	std::cout << "INT: " << i << std::endl
}

Type	typeDetector(std::string input)
{
	std::string::const_iterator i;

	i = input.begin();
	if (input.size() == 1)
	{
		if (isdigit(*i))
			return (in);
		else
			return (ch);
	}
	while (i != input.end() && isdigit(*i))//Serveix de moment pero s'han d'afegir tota la pesca de nans i nanf i el que sigui. tambe cal apendre que son el nan nanf i tota la pesca
		i++;
	if (i == input.end())
		return (in);
	else if (*i == '.')
	{
		if (*(input.end() - 1) == 'f')
			return (fl);
		els
			return (db);
	}
	else//aqui es podria fer el check de que posa(nan, nanf, etc)
		return (er);
}

int		toInt(double d, float f)
{

}


//METHODS

void	ScalarConverter::convert(std::string input)
{
	Type	type;
	char		c;
	int			i;
	float		f;
	double		d;

	c = 0;
	i = 0;
	d = 0;
	f = 0;
	type = typeDetector(input);
	switch((int) type)
	{
		case 0:
			c = input[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		case 1:
			i = (atoi(input.c_str()));
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		case 2:
			f = (atof(input.c_str()));
			i = toInt(d, f);
			c = static_cast<char>(f);
			d = static_cast<double>(f);
		case 3:
			d = (atof(input.c_str()));
			i = toInt(d, f);
			f = toFloat(d);
			c = static_cast<char>(d);
		default:
			std::cout << "If you see me, weep";	
	}
	print(c, i, f, d);
}
