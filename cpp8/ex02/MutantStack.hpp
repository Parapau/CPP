/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:24:01 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/11 15:48:31 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>//may be useless

template <typename T>
class StackIterator;
template <typename T>
class StackReverseIterator;

template <typename T>
class MutantStack
{
	private:
		std::stack<T>	stack;

		std::stack<T>	&getStack();
	public:
		MutantStack(void);
		MutantStack(const MutantStack &og);
		~MutantStack(void);

		//Iteration stuff

		typedef StackIterator<T>			iterator;
		typedef StackReverseIterator<T>		reverse_iterator;

		iterator	begin(void);
		iterator	end(void);

		iterator	rbegin(void);
		iterator	rend(void);

		T			&getPos(int i);
		//Basic stack stuff
		bool		operator==(const MutantStack &comp);//the man has a different prototype
		bool		operator!=(const MutantStack &comp);//but it may be for a newer version
		bool		operator<=(const MutantStack &comp);//since here it must be binary
		bool		operator>=(const MutantStack &comp);//(wich for some reason means only
		bool		operator<(const MutantStack &comp);//one arg);
		bool		operator>(const MutantStack &comp);

		void		push(T const&);
		void		pop(void);
		T			&top(void);
		const T		&top(void) const;
		bool		empty(void) const;
		int			size(void) const;
		void		swap(MutantStack &other);//apparently emplace is from 11 :')
	//	void		emplace(T &&args);//emplace is for when you are adding a non-primitive variable to the stack
};//push makes a temporary copy of the arg before adding it to the stack, emplace creates it directly, it's more efficient for objects (especially complex ones)

template <typename T>
class StackIterator
{
	protected://TODO: ovehaulejar aixo i posar una referencia/punter al stack original, iterar amb i retornar la posicio en al que estigui de la referencia
		int			i;
		MutantStack<T>		*ms;
	public://this garbage might get the axe
/*
		using	iterator_category = std::output_iterator_tag;
		using	value_type = MutantStack<T>;
		using	difference_type = std::ptrdiff_t;
		using	pointer = MutantStack<T>*;
		using	reference = MutantStack<T>&;
*/

		StackIterator(void);
		StackIterator(MutantStack<T>* ptr);//si algo on furula mira aqui perquè gilipolles, elabora una mica enn els teus comentaris
		StackIterator(MutantStack<T>* ptr, int i);
		StackIterator(const StackIterator &Iterator);

		~StackIterator(void);

		StackIterator		operator=(const StackIterator &other);
		StackIterator		operator=(MutantStack<T> &other);

		bool		operator==(const StackIterator &other);
		bool		operator!=(const StackIterator &other);

		StackIterator	&operator+=(const int mov);
		StackIterator	&operator-=(const int mov);
		StackIterator	&operator++(void);
		StackIterator	&operator--(void);
		StackIterator	operator++(int);
		StackIterator	operator--(int);
		StackIterator	operator+(const int mov);
		StackIterator	operator-(const int mov);

		int				operator-(const StackIterator<T> &it);

		T				&operator*(void);
		const	T		&operator*(void) const;
		T				*operator->(void);

		MutantStack<T>			*getPtr(void) const;
		const MutantStack<T>	*getConstPtr(void) const;

		int						getI(void) const;
};

template <typename T>
class StackReverseIterator: public StackIterator<T>
{
	public:
		StackReverseIterator(void);
		StackReverseIterator(MutantStack<T>* ptr);//si algo on furula mira aqui
		StackReverseIterator(const StackReverseIterator &Iterator);

		~StackReverseIterator(void);

		bool		operator==(const StackReverseIterator &other);
		bool		operator!=(const StackReverseIterator &other);

		StackReverseIterator	&operator+=(const int mov);
		StackReverseIterator	&operator-=(const int mov);
		StackReverseIterator	&operator++(void);
		StackReverseIterator	&operator--(void);
		StackReverseIterator	operator++(int);
		StackReverseIterator	operator--(int);
		StackReverseIterator	operator+(const int mov);
		StackReverseIterator	operator-(const int mov);

		int						operator-(const StackReverseIterator &it);
};

#endif
