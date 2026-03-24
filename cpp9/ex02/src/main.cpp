/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:31:30 by pafranco          #+#    #+#             */
/*   Updated: 2026/03/24 14:36:25 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

bool isNum(char *s)
{
	for (int i = 0 ; s[i] != 0 ; i++)
	{
		if (!std::isdigit(s[i]))
			throw(Merger::BadInput());
	}
	return (true);
}

static void		print(std::deque<int> *vec)
{
	for (std::deque<int>::iterator	iter = vec->begin() ; iter != vec->end() ; iter++)
		std::cout << *iter << ' ';
	std::cout << std::endl;
}

void	parse(char **argv, std::vector<int> *vec, std::deque<int> *que)
{
	for (int	i = 0 ; argv[i] != 0 ; i++)
	{
		if (isNum(argv[i]))
		{
			int		num;

			num = atoi(argv[i]);
			vec->push_back(num);
			que->push_back(num);
		}
		else
			throw (Merger::BadInput());
	}
}

int		main(int argc, char **argv)
{
	std::vector<int>	vec;
	std::deque<int>		que;
	double				start;
	double				vecTime;
	double				queTime;

	if (argc < 2)
	{
		std::cout << "No input given >:(" << std::endl;
		return (0);
	}
	try
	{
	parse(argv + 1, &vec, &que);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::cout << "Unsorted numbers:" << std::endl;
	print(&que);
	std::cout << std::endl;
	start = std::clock();
	Merger::sortVector(&vec);
	vecTime = std::clock() - start;
	start = std::clock();
	Merger::sortDeque(&que);
	queTime = std::clock() - start;
	std::cout << "Sorted numbers:" << std::endl;
	print(&que);
	std::cout << std::endl;
	std::cout << "Time taken by Vector " << vecTime << "µs" << std::endl;
	std::cout << std::endl;
	std::cout << "Time taken by Deque " << queTime << "µs" << std::endl;

}
