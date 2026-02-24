/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:53:07 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/24 14:57:58 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../RPN.hpp"

//CONSTRUCTORS

rotaluklak::rotaluklak(void)
{
}

//DESTRUCTORS

rotaluklak::~rotaluklak(void)
{
}

//OPERATIONS

void		sum(std::list<long long> *nums)
{
	long long		num1;

	num1 = nums->front();
	nums->pop_front();
	nums->front() += num1;
}

void		rest(std::list<long long> *nums)
{
	long long		num1;

	num1 = nums->front();
	nums->pop_front();
	nums->front() -= num1;
}

void		mult(std::list<long long> *nums)
{
	long long		num1;

	num1 = nums->front();
	nums->pop_front();
	nums->front() *= num1;
}

void		div(std::list<long long> *nums)
{
	long long		num1;

	num1 = nums->front();
	nums->pop_front();
	nums->front() /= num1;
}

//FUNCTIONS

static bool isNum(std::string s)
{
	std::string::iterator	i;

	i = s.begin();
	while(i != s.end())
	{
		if (!std::isdigit(*i))
			return (false);
		i++;
	}
	return (true);
}

void operate(std::list<long long> *nums, std::string sign)
{
	if (distance(nums->begin(), nums->end()) < 2 || sign.size() != 1)
		throw (rotaluklak::Bad());
	switch (sign[0])
	{
		case ('+'):
			sum(nums);
			return ;
		case ('-'):
			rest(nums);
			return ;
		case ('*'):
			mult(nums);
			return ;
		case ('/'):
			div(nums);
			return ;
		default:
			throw (rotaluklak::Bad());
	}
}

//METHODS

long long		rotaluklak::kurwa(std::string input)
{
	std::string				num;
	std::stringstream		s(input);
	std::list<long long>	nums;

	while (s >> num)
	{
		if (isNum(num))
			nums.push_front(std::atoi(num.c_str()));
		else 
			operate(&nums, num);
	}
	if (distance(nums.begin(), nums.end()) != 1)
		throw (rotaluklak::Bad());
	return (nums.front());
}

//EXCEPTIONS

const char		*rotaluklak::Bad::what() const throw()
{
	return ("ERROR");
}



