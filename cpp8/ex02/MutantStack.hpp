/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:24:01 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/09 17:24:06 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>//may be useless

class StackIterator;
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

		typedef StackIterator			iterator;
		typedef StackReverseIterator	reverse_iterator;

		iterator	begin(void);
		iterator	end(void);

		iterator	rbegin(void);
		iterator	rend(void);

		T			&getPos(int i);
		//Basic stack stuff
		bool		operator==(const MutantStack<T> &comp);//the man has a different prototype
		bool		operator!=(const MutantStack<T> &comp);//but it may be for a newer version
		bool		operator<=(const MutantStack<T> &comp);//since here it must be binary
		bool		operator>=(const MutantStack<T> &comp);//(wich for some reason means only
		bool		operator<(const MutantStack<T> &comp);//one arg);
		bool		operator>(const MutantStack<T> &comp);

		void		push(const T &e);
		void		pop(void);
		T			&top(void);
		const T		&top(void) const;
		bool		empty(void) const;
		int			size(void) const;
		void		swap(MutantStack &other);
		void		emplace(T &&args);//emplace is for when you are adding a non-primitive variable to the stack
};//push makes a temporary copy of the arg before adding it to the stack, emplace creates it directly, it's more efficient for objects (especially complex ones)

class StackIterator
{
	protected://TODO: ovehaulejar aixo i posar una referencia/punter al stack original, iterar amb i retornar la posicio en al que estigui de la referencia
		StackIterator	*elem;//aixo se'n va a la puta
		int				i;
	public://this garbage might get the axe
		using	iterator_category = std::output_iterator_tag;
		template <typename T>
		using	value_type = MutantStack<T>;
		using	difference_type = std::ptrdiff_t;
		template <typename T>
		using	pointer = MutantStack<T>*;
		template <typename T>
		using	reference = MutantStack<T>&;


		StackIterator(void);
		template <typename T>
		StackIterator(MutantStack<T>* ptr);//si algo on furula mira aqui perque gilipolles, elabora una mica enn els teus comentaris
		StackIterator(const StackIterator &Iterator);

		~StackIterator(void);

		StackIterator		operator=(const StackIterator &other);
		template <typename T>
		StackIterator		operator=(MutantStack<T> &other);

		bool		operator==(const StackIterator &other);
		bool		operator!=(const StackIterator &other);

		StackIterator	&operator+=(const difference_type &mov);
		StackIterator	&operator-=(const difference_type &mov);
		StackIterator	&operator++(void);
		StackIterator	&operator--(void);
		StackIterator	operator++(int);
		StackIterator	operator--(int);
		StackIterator	operator+(const difference_type &mov);
		StackIterator	operator-(const difference_type &mov);

		difference_type	operator-(const StackIterator &it);

		template <typename T>
		MutantStack<T>	&operator*(void);
		template <typename T>
		const	MutantStack<T>	&operator*(void) const;
		template <typename T>
		MutantStack<T>	*operator->(void);

		template <typename T>
		MutantStack<T>			*getPtr(void) const;
		template <typename T>
		const MutantStack<T>	*getConstPtr(void) const;

		int						getI(void) const;
};

class StackReverseIterator: public StackIterator
{
	public:
		StackReverseIterator(void);
		template <typename T>
		StackReverseIterator(MutantStack<T>* ptr);//si algo on furula mira aqui
		StackReverseIterator(const StackReverseIterator &Iterator);

		~StackReverseIterator(void);

		bool		operator==(const StackReverseIterator &other);
		bool		operator!=(const StackReverseIterator &other);

		StackReverseIterator	&operator+=(const difference_type &mov);
		StackReverseIterator	&operator-=(const difference_type &mov);
		StackReverseIterator	&operator++(void);
		StackReverseIterator	&operator--(void);
		StackReverseIterator	operator++(int);
		StackReverseIterator	operator--(int);
		StackReverseIterator	operator+(const difference_type &mov);
		StackReverseIterator	operator-(const difference_type &mov);

		difference_type	operator-(const StackReverseIterator &it);
};

#endif
