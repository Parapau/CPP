#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span
{
	private:
		int		*arr;
		unsigned int		size;
	public:
		Span(void);
		Span(int n);
		Span(Span &og);
		~Span(void);

		int		getSize(void);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addNumber(int num);
};

#endif
