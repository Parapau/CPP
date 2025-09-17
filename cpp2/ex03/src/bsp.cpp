/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:47:50 by pafranco          #+#    #+#             */
/*   Updated: 2025/09/17 18:50:14 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"
#include "../Point.hpp"

static float	area(Point &v1, Point &v2, Point &v3)
{
   return abs((v1.getX() * (v2.getY() - v3.getY())
			+ v2.getX() * (v3.getY() - v1.getY())
			+ v3.getX() * (v1.getY() - v2.getY())) / 2.0);
}

bool	bsp(Point &v1, Point &v2, Point &v3, Point &p)
{
	int		area1;
	int		area2;
	int		area3;
	int		areaOG;

	areaOG = area(v1, v2, v3);
	area1 = area(v1, v2, p);
	area2 = area(v1, p, v3);
	area3 = area(p, v2, v3);
	return (areaOG == area1 + area2 + area3);
}
