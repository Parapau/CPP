/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:08:33 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/21 15:49:56 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T1, typename T2>
void	iter(T1 &arr, int len, T2 func)
{
	int		i;

	i = 0;
	while (i < len)
	{	
		func(arr[i]);
		i++;
	}
}

template <typename T>
void	prunt(T &x)
{
	std::cout << x << std::endl;
}

#endif
