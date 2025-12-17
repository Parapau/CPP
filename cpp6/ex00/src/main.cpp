/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:18:19 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/17 19:58:49 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScalarConverter.hpp"
#include <limits>

int	main(void)
{
	ScalarConverter::convert("4");
	std::cout << std::endl;
	ScalarConverter::convert("-2");
	std::cout << std::endl;
	ScalarConverter::convert("c");
	std::cout << std::endl;
	ScalarConverter::convert("4.4989f");
	std::cout << std::endl;
	ScalarConverter::convert("4.4983");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
}
