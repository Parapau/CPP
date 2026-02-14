/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:08:04 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/14 17:13:28 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << mstack << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
		if (it == ite)
			std::cout << "puta espanya";
	}
	//std::stack<int> s(mstack);
	return (0);
}
