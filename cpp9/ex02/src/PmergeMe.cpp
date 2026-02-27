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
}

static void		swap(std::vector<int>::iterator vec, int num)
{
	int		temp;

	for (int i = 0 ; i < num / 2 ; i ++)
	{
		temp = *(vec + i);
		*(vec + i) = *(vec + (i + (num / 2)));
		*(vec + i + (num / 2)) = temp;
	}
}

static void		insert(std::vector<int> main, std::vector<int>::iterator vec, int num, int pos)
{
	for (int i = 0 ; i < num ; i++)
	{


		
	}
}

static void		jacob(std::vector<int> *vec, int size)
{
	std::vector<int>	main;
	std::vector<int>	pend;
	int					mode;

	mode = -2;//may need to be -1
	for (std::vector<int>::iterator iter = vec->begin() ; iter != vec->end() ; iter++)
	{
		if (mode == 0)
			main.push_back(*iter);
		else
			pend.push_back(*iter);
		if (mode != 0 && iter % (size / 2) == 0)
			mode++;
		else if (iter % (size / 2) == 0)
			mode = 0;
	}
}

static void		pair(std::vector<int> vec, int size)
{
	int						i;
	std::vector<int>::iterator	iter = vec.begin();

	i = 0;
	size = size * 2;
	for (std::vector<int>::iterator	iter = vec.begin() ;
			iter != vec.end() ; iter + size)
	{
		if (*(iter + ((size / 2) - 1)) < (*(iter + (size - 1))))
			swap(iter, size);
	}
	if (vec.size() > size * 2)
		pair(vec, size);



}

//METHODS

void	sort(int *arr)
{
	
}

//EXCEPTIONS

const char		*Merger::BadInput::what() const throw()
{
	return ("Your input is bad and so are you >:(");
}
