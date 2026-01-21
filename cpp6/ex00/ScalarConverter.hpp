/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:49:48 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/17 19:54:46 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <string>

enum Type
{
	ch,
	in,
	fl,
	db,
	spf,
	spd,
	er
};

class ScalarConverter
{
	private:
		ScalarConverter(void){}
		~ScalarConverter(void){}
	public:
		static void			convert(std::string input);
};
