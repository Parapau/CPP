#ifndef MUTANTSATCK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>//may be useless

template <typename T>
class MutantStack
{
	private:
		std::stack<T>	stack;
		std::stack<T>	iter;//may be useless

		std::stack<T>	getStack();
		int				getSize();
	public:
		MutantStack(void);
		MutantStack(MutantStack &og);
		~MutantStack(void);

		void		push(T n);
		void		pop(T n);
		T			top(void);
		bool		empty(void);
		int			size(void);


};

#endif
