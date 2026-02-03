/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:11:41 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/03 15:50:37 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Span.hpp"

//CONSTRUCTOR

Span::Span(void): size(0), mSize(0)
{
}

Span::Span(unsigned int n):size(0), mSize(n)
{
}

Span::Span(Span &og): st(getSet()), size(og.getSize()), mSize(og.getMSize())
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

	newSet = og.getSet();//i think this should make a hardcopy, but i'm not sure :)
	setSize(og.getSize());
	setMSize(og.getMSize());
	setSet(newSet);//although it might jus make sure it gets deleted when the funtion ends bc it's in the stack🤙
	return (*this);
}

//METHODS

int		Span::shortestSpan(void)
{
	std::multiset<int>::iterator	i;
	unsigned int		dif;
	int					lastNum;

	if (getSize() <= 1)
		throw (std::exception());
	dif = 0;
	i = getSet().begin();
	lastNum = *i;
	while (i != getSet().end())
	{
		
	}
	return (0);
}

int		Span::longestSpan(void)
{
	return (*getSet().rbegin() - *getSet().begin());
}

void	Span::addNumber(int n)
{
	if (getMSize() > getSize() + 1)
		throw (std::exception());
	setSize(getSize() + 1);
	getSet().insert(n);
}

//SETTERS

void	Span::setSize(unsigned int n)
{
	this->size = n;
}

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
	return (this->size);
}

int		Span::getMSize(void)
{
	return (this->mSize);
}

std::multiset<int>	Span::getSet(void)
{
	return (this->st);
}
