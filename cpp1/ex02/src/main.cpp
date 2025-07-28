/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:21:53 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 19:32:07 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	s;
	std::string	*ptr;
	std::string	&ref = s;

	s = "HI THIS IS BRAIN";
	ptr = &s;
	std::cout << &s << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;
	std::cout << s << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}
