/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:56:21 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/11 13:37:23 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MutantStack.hpp"

//****************************STACK ITERATOR********************************

//CONSTRUCTORS

template <typename T>
StackIterator<T>::StackIterator(void):i(0)
{
}

template <typename T>
StackIterator<T>::StackIterator(MutantStack<T> *ptr):i(0), ms(ptr)
{
}

template <typename T>
StackIterator<T>::StackIterator(MutantStack<T> *ptr, int i):i(i), ms(ptr)
{
}

template <typename T>
StackIterator<T>::StackIterator(const StackIterator &Iterator):i(Iterator.getI())
{
	*this = Iterator;
}

//DESTRUCTOR

template <typename T>
StackIterator<T>::~StackIterator(void)//leak?????
{
}


//OVERLOADS

template <typename T>
StackIterator<T>	StackIterator<T>::operator=(const StackIterator &other)
{
	this->ms = other.getPtr();
	this->i = other.getI();
	return (*this);
}

template <typename T>
StackIterator<T>	StackIterator<T>::operator=(MutantStack<T> &other)
{
	this->ms = other.getPtr();
	this->i = other.getI();
	return (*this);
}

template <typename T>
bool		StackIterator<T>::operator==(const StackIterator &other)
{
	return (getI() == other.getI() && *(this->getPtr()) == *(other.getPtr()));
}

template <typename T>
bool		StackIterator<T>::operator!=(const StackIterator &other)
{
	return (getI() != other.getI() || this->getPtr() != other.getPtr());
}

template <typename T>
StackIterator<T>	&StackIterator<T>::operator+=(const int mov)
{
	this->i += mov;
	if (getI() >= getPtr()->size())
		this->i = getPtr()->size();
	return (*this);
}

template <typename T>
StackIterator<T>	&StackIterator<T>::operator-=(const int mov)
{
	this->i -= mov;
	if (getI() < 0)
		this->i = 0;
	return (*this);
}

template <typename T>
StackIterator<T>	&StackIterator<T>::operator++(void)
{
	this->i += 1;
	if (getI() >= getPtr()->size())
		this->i = getPtr()->size();
	return (*this);
}

template <typename T>
StackIterator<T>	&StackIterator<T>::operator--(void)
{
	this->i -= 1;
	if (getI() < 0)
		i = 0;
	return (*this);
}

template <typename T>
StackIterator<T>	StackIterator<T>::operator++(int)
{
	this->i += 1;
	if (getI() >= ms->size())
		this->i = getPtr()->size() + 1;
	return (*this);
}

template <typename T>
StackIterator<T>	StackIterator<T>::operator--(int)
{
	this->i -= 1;
	if (getI() < 0)
		this->i = 0;
	return (*this);
}

template <typename T>
StackIterator<T>	StackIterator<T>::operator+(const int mov)
{
	this->i += mov;
	if (getI() >= ms->size())
		this->i = ms->size() + 1;
	return (*this);
}

template <typename T>
StackIterator<T>	StackIterator<T>::operator-(const int mov)
{
	this->i -= mov;
	if (getI() < 0)
		this->i = 0;
	return (*this);
}

template <typename T>
int	StackIterator<T>::operator-(const StackIterator &it)
{
	return (getI() - it.getI());
}

template <typename T>
T	&StackIterator<T>::operator*(void)
{
	return (this->getPtr()->getPos(this->getI()));
}

template <typename T>
const T	&StackIterator<T>::operator*(void) const
{
	return (getPtr()->getPos(getI()));
}

template <typename T>
T	*StackIterator<T>::operator->(void)
{
	return (&getPtr()->getPos(getI()));
}

//GETTERS

template <typename T>
MutantStack<T>	*StackIterator<T>::getPtr(void) const
{
	return (ms);
}

template <typename T>
const MutantStack<T>	*StackIterator<T>::getConstPtr(void) const
{
	return (ms);
}

template <typename T>
int		StackIterator<T>::getI(void) const
{
	return (this->i);
}

//****************************STACK REVERSE ITERATOR********************************

//CONSTRUCTORS

template <typename T>
StackReverseIterator<T>::StackReverseIterator(void)
{
}

template <typename T>
StackReverseIterator<T>::StackReverseIterator(MutantStack<T> *ptr)
{
	this->i = ptr->size() - 1;
	this->ms = ptr;
}

template <typename T>
StackReverseIterator<T>::StackReverseIterator(const StackReverseIterator &Iterator)
{
	*this = Iterator;
}

//DESTRUCTOR

template <typename T>
StackReverseIterator<T>::~StackReverseIterator(void)
{
}

//OVERLOADS

template <typename T>
bool		StackReverseIterator<T>::operator==(const StackReverseIterator &other)
{
	return (this->getI() == other.getI() && this->getPtr() == other.getPtr());
}

template <typename T>
bool		StackReverseIterator<T>::operator!=(const StackReverseIterator &other)
{
	return (this->getI() != other.getI() || this->getPtr() != other.getPtr());
}

template <typename T>
StackReverseIterator<T>	&StackReverseIterator<T>::operator+=(const int mov)
{
	this->i -= mov;
	if (this->getI() < -1)
		this->i = -1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	&StackReverseIterator<T>::operator-=(const int mov)
{
	this->i += mov;
	if (this->getI() > this->getPtr()->size())
		this->i = this->getPtr()->size() - 1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	&StackReverseIterator<T>::operator++(void)
{
	this->i -= 1;
	if (this->getI() < -1)
		this->i = -1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	&StackReverseIterator<T>::operator--(void)
{
	this->i += 1;
	if (this->getI() > this->getPtr()->size())
		this->i = this->getPtr()->size() - 1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	StackReverseIterator<T>::operator++(int)
{
	this->i -= 1;
	if (this->getI() < -1)
		this->i = -1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	StackReverseIterator<T>::operator--(int)
{
	this->i += 1;
	if (this->getI() > this->getPtr()->size())
		this->i = this->getPtr()->size() - 1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	StackReverseIterator<T>::operator+(const int mov)
{
	this->i -= mov;
	if (this->getI() < -1)
		this->i = -1;
	return (*this);
}

template <typename T>
StackReverseIterator<T>	StackReverseIterator<T>::operator-(const int mov)
{
	this->i += mov;
	if (this->getI() > this->getPtr()->size())
		this->i = this->getPtr()->size() - 1;
	return (*this);
}

template <typename T>
int	StackReverseIterator<T>::operator-(const StackReverseIterator &it)
{
	return (this->getI() - it.getI());
}
