/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:44:51 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/27 12:19:13 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
# define PMERGE_ME

#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <sstream>
#include <cmath>

class Merger
{
	private:
		int		_size;
		
		Merger(void);
		~Merger(void);
	public:
		static void		sort(std::vector<int> vec);
		static void		sort(int *arr);

	class BadInput: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
