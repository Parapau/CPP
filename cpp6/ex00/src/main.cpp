/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:18:19 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/15 19:24:53 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ScalarConverter.hpp"
#include <limits>

int	main(void)
{
	std::cout << std::numeric_limits<double>::max() << std::endl
		<< std::numeric_limits<float>::max() << std::endl
		<< std::numeric_limits<int>::max() << std::endl;
}
