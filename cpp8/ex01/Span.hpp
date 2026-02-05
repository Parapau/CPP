#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <iterator>
#include <set>

class Span
{
	private:
		std::multiset<int>		st;
		unsigned int			mSize;

		void				setMSize(unsigned int n);
		void				setSet(std::multiset<int> st);
		int					getSize(void);
		int					getMSize(void);
		std::multiset<int>	&getSet(void);
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span &og);
		~Span(void);
		Span	&operator=(Span &og);

		int					shortestSpan(void);
		int					longestSpan(void);
		void				addNumber(int num);
		void				addNumber(int num1, int num2);
};

#endif
