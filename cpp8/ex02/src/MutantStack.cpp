/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:14:03 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/09 17:03:41 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MutantStack.hpp"

//CONSTRUCTORS

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &og): stack(og.getStack())
{
}

//DESTRUCTORS

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	delete	(getStack());
}

//ITERATIONING

//template <typename T>
/*
StackIterator	MutantStack<T>::begin(void)
{
	return (0);
}*/

//OVERLOADS

template <typename T>
bool		MutantStack<T>::operator==(const MutantStack<T> &comp)
{
	return (*this == comp);
}

template <typename T>
bool		MutantStack<T>::operator!=(const MutantStack<T> &comp)
{
	return (*this != comp);
}

template <typename T>
bool		MutantStack<T>::operator<=(const MutantStack<T> &comp)
{
	return (*this <= comp);
}

template <typename T>
bool		MutantStack<T>::operator>=(const MutantStack<T> &comp)
{
	return (*this >= comp);
}

template <typename T>
bool		MutantStack<T>::operator<(const MutantStack<T> &comp)
{
	return (*this < comp);
}

template <typename T>
bool		MutantStack<T>::operator>(const MutantStack<T> &comp)
{
	return (*this > comp);
}

//METHODS

template <typename T>
void	MutantStack<T>::push(const T &e)
{
	getStack().push(e);
}

template <typename T>
void	MutantStack<T>::pop(void)
{
	getStack().pop();
}

template <typename T>
T	&MutantStack<T>::top(void)
{
	getStack().top();
}

template <typename T>
const T	&MutantStack<T>::top(void) const
{
	getStack().top();
}

template <typename T>
bool	MutantStack<T>::empty(void) const
{
	getStack().empty();
}

template <typename T>
int	MutantStack<T>::size(void) const
{
	getStack().size();
}

template <typename T>
void	MutantStack<T>::swap(MutantStack &other)
{
	getStack().swap();
}

template <typename T>
void	MutantStack<T>::emplace(T &&args)
{
	getStack().emplace(args);
}

//GETTERS

template <typename T>
std::stack<T>	&MutantStack<T>::getStack(void)
{
	return (this->stack);
}

template <typename T>
T				&MutantStack<T>::getPos(int n)
{
	std::stack<T>	iter = (*this);
	int				i;

	for (i = 0; i <= n && i < size(); i++)//Potser he d'acceptar que sigui major per fer la "null temrinacio" del iter
		iter.pop();
	if (i < n)
		throw (std::exception());//TODO excepcio custom (possibly)
	return (iter.top());
}
