/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:23:05 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/05 12:30:57 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Span.hpp"

int	main (void)
{
	Span	pan(5);
	Span	pin(5);
	Span	pon(10000);

	pan.addNumber(1);
	pan.addNumber(3);
	pan.addNumber(-4);
	pan.addNumber(5);
	pan.addNumber(100);

	std::cout << pan.longestSpan() << std::endl << pan.shortestSpan() << std::endl;

	pin.addNumber(0, 10);

	std::cout << pin.longestSpan() << std::endl << pin.shortestSpan() << std::endl;

	pon.addNumber(-10000, 500);

	std::cout << pon.shortestSpan() << std::endl << pon.longestSpan() << std::endl;
}
