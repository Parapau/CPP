/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:11:41 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/05 13:00:53 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Span.hpp"

//CONSTRUCTOR

Span::Span(void): mSize(0)
{
}

Span::Span(unsigned int n): mSize(n)
{
}

Span::Span(Span &og): st(getSet()), mSize(og.getMSize())
{
}

//DESTRUCTOR

Span::~Span(void)
{
}

//OVERLOAD

Span	&Span::operator=(Span &og)
{
	std::multiset<int>		newSet;

	newSet = og.getSet();
	setMSize(og.getMSize());
	setSet(newSet);
	return (*this);
}

//METHODS

int		Span::shortestSpan(void)
{
	std::multiset<int>::iterator	i;
	long							dif;
	long							num;

	if (getSize() <= 1)
		throw (std::exception());
	i = getSet().begin();
	num = *i;
	i++;
	dif = *i - num;
	num = *i;
	i++;
	while (i != getSet().end())
	{
		if ((unsigned int) (*i - num) < dif)
			dif = *i - num;
		if (dif == 0)
			return (0);
		num = *i;
		i++;
	}
	return (dif);
}

int		Span::longestSpan(void)
{
	if (getSize() <= 1)
		throw (std::exception());
	return (*getSet().rbegin() - *getSet().begin());
}

void	Span::addNumber(int n)
{
	if (getMSize() < getSize() + 1)
		throw (std::exception());
	getSet().insert(n);
}

void	Span::addNumber(int num1, int num2)
{
	int		num3;
	int		size;

	num3 = 0;
	size = getMSize() - getSize();
	if (num1 == num2)
	{
		addNumber(num1);
		return ;
	}
	if (size < 2)
		throw (std::exception());
	if (num1 > num2)
	{
		num3 = num1;
		num1 = num2;
		num2 = num3;
	}
	num3 = (num2 - num1) / size;
	if (num3 == 0)
		num3 = 1;
	for (int i = 0 ; num1 + i <= num2 && getSize() < getMSize() - 1 ; i += num3)
		addNumber(num1 + i);
	addNumber(num2);
}

//SETTERS

void	Span::setMSize(unsigned int n)
{
	this->mSize = n;
}

void	Span::setSet(std::multiset<int> st)
{
	this->st = st;
}

//GETTERS


int		Span::getSize(void)
{
	return (getSet().size());
}

int		Span::getMSize(void)
{
	return (this->mSize);
}

std::multiset<int>	&Span::getSet(void)
{
	return (this->st);
}
