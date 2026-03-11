/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:31:30 by pafranco          #+#    #+#             */
/*   Updated: 2026/03/11 17:13:03 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

int		main(void)
{
	int					arr[8] = {1, 3, 8, 9, 2, 5, 6, 4};
	std::vector<int>	vec;

	for (int i = 0; i < 8 ; i++)
		vec.push_back(arr[i]);
	Merger::sort(&vec);
}
