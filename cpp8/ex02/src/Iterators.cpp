/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:56:21 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/09 17:13:24 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MutantStack.hpp"

//****************************STACK ITERATOR********************************

//CONSTRUCTORS

StackIterator::StackIterator(void):i(0)
{
}

template <typename T>
StackIterator::StackIterator(MutantStack<T> *ptr):i(0)
{
	elem = ptr;
}

StackIterator::StackIterator(const StackIterator &Iterator):i(Iterator.getI())
{
	*this = Iterator;
}

//DESTRUCTOR

StackIterator::~StackIterator(void)
{
}


//OVERLOADS

StackIterator	StackIterator::operator=(const StackIterator &other)
{
	this->elem = other.elem;
	return (*this);
}

template <typename T>
StackIterator	StackIterator::operator=(MutantStack<T> &other)
{
	this->elem = other.elem;
	return (*this);
}

bool		StackIterator::operator==(const StackIterator &other)
{
	return (elem == other.elem);
}

bool		StackIterator::operator!=(const StackIterator &other)
{
	return (elem != other.elem);
}


StackIterator	&StackIterator::operator+=(const difference_type &mov)
{
	elem += mov;
	return (*this);
}

StackIterator	&StackIterator::operator-=(const difference_type &mov)
{
	elem -= mov;
	return (*this);
}

StackIterator	&StackIterator::operator++(void)
{
	elem += 1;
	return (*this);
}

StackIterator	&StackIterator::operator--(void)
{
	elem -= 1;
	return (*this);
}

StackIterator	StackIterator::operator++(int)
{
	elem += 1;
	return (*this);
}

StackIterator	StackIterator::operator--(int)
{
	elem -= 1;
	return (*this);
}

StackIterator	StackIterator::operator+(const difference_type &mov)
{
	elem += mov;
	return (*this);
}

StackIterator	StackIterator::operator-(const difference_type &mov)
{
	elem -= mov;
	return (*this);
}

StackIterator::difference_type	StackIterator::operator-(const StackIterator &it)
{
	return (std::distance(this->elem, it.elem));
}

template <typename T>
MutantStack<T>	&StackIterator::operator*(void)
{
	return (*getPtr<T>());
}

template <typename T>
const MutantStack<T>	&StackIterator::operator*(void) const
{
	return (*getPtr<T>());
}

template <typename T>
MutantStack<T>	*StackIterator::operator->(void)
{
	return (getPtr<T>());
}

//GETTERS

template <typename T>
MutantStack<T>	*StackIterator::getPtr(void) const
{
	return (elem);
}

template <typename T>
const MutantStack<T>	*StackIterator::getConstPtr(void) const
{
	return (elem);
}

int		StackIterator::getI(void) const
{
	return (this->i);
}

//****************************STACK REVERSE ITERATOR********************************

//CONSTRUCTORS

StackReverseIterator::StackReverseIterator(void)
{
}

template <typename T>
StackReverseIterator::StackReverseIterator(MutantStack<T> *ptr)
{
	elem = ptr;
}

StackReverseIterator::StackReverseIterator(const StackReverseIterator &Iterator)
{
	*this = Iterator;
}

//DESTRUCTOR

StackReverseIterator::~StackReverseIterator(void)
{
}

//OVERLOADS

bool		StackReverseIterator::operator==(const StackReverseIterator &other)
{
	return (elem == other.elem);
}

bool		StackReverseIterator::operator!=(const StackReverseIterator &other)
{
	return (elem != other.elem);
}


StackReverseIterator	&StackReverseIterator::operator+=(const difference_type &mov)
{
	elem += mov;
	return (*this);
}

StackReverseIterator	&StackReverseIterator::operator-=(const difference_type &mov)
{
	elem -= mov;
	return (*this);
}

StackReverseIterator	&StackReverseIterator::operator++(void)
{
	elem += 1;
	return (*this);
}

StackReverseIterator	&StackReverseIterator::operator--(void)
{
	elem -= 1;
	return (*this);
}

StackReverseIterator	StackReverseIterator::operator++(int)
{
	elem += 1;
	return (*this);
}

StackReverseIterator	StackReverseIterator::operator--(int)
{
	elem -= 1;
	return (*this);
}

StackReverseIterator	StackReverseIterator::operator+(const difference_type &mov)
{
	elem += mov;
	return (*this);
}

StackReverseIterator	StackReverseIterator::operator-(const difference_type &mov)
{
	elem -= mov;
	return (*this);
}

StackReverseIterator::difference_type	StackReverseIterator::operator-(const StackReverseIterator &it)
{
	return (std::distance(this->elem, it.elem));
}
