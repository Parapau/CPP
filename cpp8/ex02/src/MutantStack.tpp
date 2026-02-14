/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:14:03 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/13 14:34:39 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MutantStack.hpp"

//CONSTRUCTORS

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &og): stack(og.getStack())
{
}

//DESTRUCTORS

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

//ITERATIONING

template <typename T>
StackIterator<T>	MutantStack<T>::begin(void)
{
	return (StackIterator<T>(this));
}

template <typename T>
StackIterator<T>	MutantStack<T>::end(void)
{
	return (StackIterator<T>(this, size()));
}

template <typename T>
StackIterator<T>	MutantStack<T>::rbegin(void)
{
	return (StackIterator<T>(this, size() - 1));
}

template <typename T>
StackIterator<T>	MutantStack<T>::rend(void)
{
	return (StackIterator<T>(this, -1));
}

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

template <typename T>
std::ostream&	operator<<(std::ostream &o, MutantStack<T> &og)
{
	std::stack<T>	iter = (og.getStack());

	for (int i = 0; i < og.size(); i++)
	{
		o << iter.top() << " ";
		iter.pop();
	}
	return (o);
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
	return (getStack().top());
}

template <typename T>
const T	&MutantStack<T>::top(void) const
{
	return (getStack().top());
}

template <typename T>
bool	MutantStack<T>::empty(void) const
{
	return (getStack().empty());
}

template <typename T>
int	MutantStack<T>::size(void) const
{
	return (stack.size());
}

template <typename T>
void	MutantStack<T>::swap(MutantStack &other)
{
	getStack().swap(other);
}

/*
template <typename T>
void	MutantStack<T>::emplace(T &&args)
{
	getStack().emplace(args);
}
*/

//GETTERS

template <typename T>
std::stack<T>	&MutantStack<T>::getStack(void)
{
	return (this->stack);
}

template <typename T>
T				&MutantStack<T>::getPos(int n)
{
	int				i;

	this->iter = (this->getStack());
	for (i = 0; i < n && i < size(); i++)
		this->iter.pop();
	if (i < n)
		throw (std::exception());//TODO excepcio custom (possibly)
	return(this->iter.top());
}
