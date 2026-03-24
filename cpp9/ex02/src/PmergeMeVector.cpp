/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:47:37 by pafranco          #+#    #+#             */
/*   Updated: 2026/03/24 14:29:04 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PmergeMe.hpp"

//CONSTUCTORS

Merger::Merger(void)
{
}

//DESTRUCTORS

Merger::~Merger(void)
{
}

//FUNCTIONS
/*
static void		print(std::vector<int> *vec)
{
	for (std::vector<int>::iterator	iter = vec->begin() ; iter != vec->end() ; iter++)
		std::cout << *iter << ' ';
	std::cout << std::endl;
}*/

static void		sub(std::vector<int> *vec, std::vector<int> *main)
{
	int		i;

	i = 0;
	for (std::vector<int>::iterator itermain = main->begin() ; itermain != main->end() && i < (int)vec->size(); itermain++)
	{
		vec->at(i) = *itermain;
		i++;
	}
}

static void		swap(std::vector<int>::iterator vec, int num)
{//swaps front with back
	int		temp;

	for (int i = 0 ; i < num / 2 ; i ++)
	{
		temp = *(vec + i);
		*(vec + i) = *(vec + (i + (num / 2)));
		*(vec + i + (num / 2)) = temp;
	}
}

static int		binary(std::vector<int> *main, int pendNum, int max, int size)
{
	int		mid;
	int		low;
	int		high;

	low = 0;
	high = max;
	while (low <= high)
	{
		mid = low + ((high - low) / 2);
		int num = main->at(size + (mid * size) - 1);
		if (num < pendNum)
			low = mid + 1;
		else if (num > pendNum)
			high = mid - 1;
		else
			return (mid);
		if (low == high && high == max)
			return (mid);
	}
	mid = low + ((high - low) / 2);
	if (mid == 1 && pendNum < main->at(size - 1))//both cases probably never going to happen now but keeping them for si de case
		mid = 0;
	if (mid == max - 1 && pendNum > main->at((max * size) - 1))
		mid = max;
	return (mid);
}

static int		simple(std::vector<int> *main, int pendNum, int size)//may need max size
{
	int		pos;

	pos = 0;
	while (main->at(size + (pos * size) - 1) < pendNum)
		pos++;
	return (pos);
}

static int		jinsert(std::vector<int> *main, std::vector<int> *pend, int jacob, int size, int *add)
{
	int								pos;
	std::vector<int>::iterator		iter;

	if ((jacob - 1) * size > (int) pend->size())
		return (0);
	if (jacob + *add > 3)
		pos = binary(main, pend->at(((jacob - 1) * size) - 1), jacob + *add, size);
	else
		pos = simple(main, pend->at(((jacob - 1) * size) - 1), size);
	for (int n = 0 ; n <= size - 1 ; n++)
	{
		iter = main->begin() + (pos * size);
		int		num = pend->at((((jacob - 1) * size) - n) - 1);
		main->insert(iter, num);
	}
	if (pos >= jacob + *add)
		return (1);//this increase to the mains size will be added later
	else
		*add += 1;
	return (0);
}

static int		findMaxJacob(int size)
{
	int		jacob;
	int		jacob1;
	int		jacobTemp;

	jacob = 1;
	jacob1 = 1;
	while (jacob < size)//maybe <=
	{
		jacobTemp = jacob;
		jacob += jacob1 * 2;
		jacob1 = jacobTemp;
	}
	return (jacob);
}

static void		jacob(std::vector<int> *vec, int size)
{
	std::vector<int>	main;
	std::vector<int>	pend;
	int					util;//util 0 == pend util != 0 main
	int					jacob;
	int					jacob1;
	int					maxJacob;

	jacob = 1;
	jacob1 = 1;
	util = -2;//may need to be -1
	for (std::vector<int>::iterator iter = vec->begin() ; iter != (vec->end() - (vec->size() % (size / 2))); iter++)
	{
		if (util <= 0 && distance(vec->begin(), iter) % (size / 2) == 0)
			util++;
		else if (distance(vec->begin(), iter) % (size / 2) == 0)
			util = 0;
		if (util <= 0)
			main.push_back(*iter);
		else
			pend.push_back(*iter);
	}
	util = 0;//util is now the extra length the main has gained
	maxJacob = findMaxJacob(((int)pend.size() / 2) + 2);
	while (jacob <= maxJacob)
	{
		int		jacobtemp;
		int		addLater = 0;//when we insert further than will be checked in the next iteration the length is counted here to be added to the total after we finish this jacobsthal level

		jacobtemp = jacob;
		jacob += jacob1 * 2;
		jacob1 = jacobtemp;
		for (int jacob2 = jacob ; jacob2 > jacob1 ; jacob2--)
		{
			addLater += jinsert(&main, &pend, jacob2, size / 2, &util);
		}
		util += addLater;
	}
	sub(vec, &main);
}

static void		pair(std::vector<int> *vec, int size)
{
	int			i;

	size = size * 2;
	i = size;
	for (std::vector<int>::iterator	iter = vec->begin() ;
			iter != vec->end() - (size - 1) ; iter++)
	{
		if (*(iter + ((size / 2) - 1)) > (*(iter + (size - 1))) && i == size)
			swap(iter, size);
		if (i == size)
			i = 0;
		i++;
	}
	if ((int) vec->size() >= size * 2)
		pair(vec, size);
	if ((int) vec->size() != size)
		jacob(vec, size);
}

//METHODS

void	Merger::sortVector(std::vector<int> *vec)
{
	pair(vec, 1);//may need size 1
}

//EXCEPTIONS

const char		*Merger::BadInput::what() const throw()
{
	return ("Your input is bad and so are you >:(");
}
