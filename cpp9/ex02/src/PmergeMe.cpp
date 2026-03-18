/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 PmergeMe.cpp										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: pafranco <pafranco@student.42barcelon		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/02/27 11:29:25 by pafranco		   #+#	  #+#			  */
/*	 Updated: 2026/02/27 13:42:58 by pafranco		  ###	########.fr		  */
/*																			  */
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
static bool isNum(std::string s)
{
	std::string::iterator	i;

	i = s.begin();
	while(i != s.end())
	{
		if (!std::isdigit(*i))
			throw(Merger::BadInput());
		i++;
	}
	return (true);
}*/

static void		print(std::vector<int> *vec)
{
	for (std::vector<int>::iterator	iter = vec->begin() ; iter != vec->end() ; iter++)
		std::cout << *iter << ' ';
	std::cout << std::endl;
}

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
	std::cout << "binaration" << std::endl;
	print(main);
	while (low != high || high - low != 1)
	{
		mid = (high - low) / 2;
		if (pendNum > main->at(((low + mid) * size) - 1))
			low = mid + 1;
		else
			high = mid - 1;
	}
	std::cout << mid << std::endl;
	return (mid);
}

static int		jinsert(std::vector<int> *main, std::vector<int> *pend, int jacob, int size, int *add)
{
	int								pos;
	int								mid;

	pos = (jacob + *add) / 2;//point in the middle
	mid = pos / 2;
	pos = binary(main, pend->at(((jacob - 2) * size) - 1), jacob + *add, size);
/*	if (pos == 0 && pend->at(((jacob - 1) * size) - 1) > main->at(size - 1))
		pos++;
	if (pos < 0)
		pos = 0;*/
	for (int n = size - 1 ; n >= 0 ; n--)
	{
		int		num = pend->at(((jacob - 2) * size) + n);
	//	print(main);
	//	std::cout << main->at(pos * size) << std::endl;
		main->insert(main->begin() + (pos * size), num);
	}
	print(main);
	if (pos >= jacob + *add)
		return (1);//this increase to the mains size will be added later
	else
		*add += 1;
	return (0);
}

static void		jacob(std::vector<int> *vec, int size)
{
	std::vector<int>	main;
	std::vector<int>	pend;
	int					util;//util 0 == pend util != 0 main
	int					jacob;
	int					jacob1;

	std::cout << "it's jacobing time" << std::endl;
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
	std::cout << "main: ";
	print(&main);
	std::cout << "pend: ";
	print(&pend);
	//both  main and pend are full now we start sorting
	util = 0;//util is now the extra length the main has gained
	while (jacob <= ((int)pend.size() / size + 2))//TODO +2 or what
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
	std::cout << "jacobs all over the place" << std::endl;
	print(vec);
}

static void		pair(std::vector<int> *vec, int size)
{
	int			i;

	size = size * 2;
	i = size;
	std::cout << "iteration level: " << size << std::endl;
	print(vec);
	for (std::vector<int>::iterator	iter = vec->begin() ;
			iter != vec->end() - (size - 1) ; iter++)
	{
		if (*(iter + ((size / 2) - 1)) > (*(iter + (size - 1))) && i == size)
		{
			swap(iter, size);
			//print(vec);
		}
		if (i == size)
			i = 0;
		i++;
	}
	if ((int) vec->size() >= size * 2)
		pair(vec, size);
	if ((int) vec->size() != size)
	{
		std::cout << "iteration level: " << size << std::endl;
		jacob(vec, size);
		std::cout << "iteration level: " << size << std::endl;
	}
	std::cout << "we are finishitationing" << std::endl;
}

//METHODS

void	Merger::sort(std::vector<int> *vec)
{
	pair(vec, 1);//may need size 1
	print(vec);
}

//EXCEPTIONS

const char		*Merger::BadInput::what() const throw()
{
	return ("Your input is bad and so are you >:(");
}
