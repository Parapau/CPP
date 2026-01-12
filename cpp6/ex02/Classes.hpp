/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:40:47 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/12 16:48:47 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base
{
	public:
		virtual ~Base(void) {}
};

class A: virtual public Base
{
};

class B: virtual public Base
{
};

class C: virtual public Base
{
};
