#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const		_x;
		Fixed const		_y;
	public:
		Point(void);
		Point(float x, float y);
		Point(Point &point);
		Point		&operator=(Point &og);
		float		getX(void);
		float		getY(void);
		void		print(void);
		~Point(void);
};

bool	bsp(Point &v1, Point &v2, Point &v3, Point &p);

#endif
