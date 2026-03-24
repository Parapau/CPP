/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:44:51 by pafranco          #+#    #+#             */
/*   Updated: 2026/03/24 14:19:40 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <time.h>
#include <sstream>
#include <cmath>
#include <ctime>

class Merger
{
	private:
		Merger(void);
		~Merger(void);
	public:
		static void		sortVector(std::vector<int> *vec);
		static void		sortDeque(std::deque<int> *vec);

	class BadInput: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
