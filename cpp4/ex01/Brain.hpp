/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:10:17 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/22 20:14:46 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string		_thoughts[100];
	public:
		Brain(void);
		Brain(std::string);
		Brain(const Brain &og);
		Brain	&operator=(const Brain &og);
		~Brain(void);

		void			think(std::string thought);
		void			thinkOutLoud(void);

		std::string		getThought(int n) const;
		void			setThought(std::string thought, int n);
};



#endif
