/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:49:48 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/15 19:32:44 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

enum Type
{
	ch,
	in,
	fl,
	db,
	er
};

enum ErrorStates
{
	IMPOSSIBLE,
	SPECIAL,
	NON_PRINT,
	BAD_INPUT
};

class ScalarConverter
{
	private:
		ScalarConverter(void){}
		~ScalarConverter(void){}
	public:
		static void			convert(std::string input);
};
