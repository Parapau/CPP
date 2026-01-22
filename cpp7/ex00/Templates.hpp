/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:08:37 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/21 15:08:54 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> T myMax (T x, T y)
{
	return ((x > y) ? x : y);
}

template <typename T> T myMin (T x, T y)
{
	return ((x < y) ? x : y);
}

template <typename T> void mySwap (T &x, T &y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}
