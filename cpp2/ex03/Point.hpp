#ifndef FIXED_HPP
# define FIXED_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const		_x;
		Fixed const		_y;
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point &point);
		Point		&operator=(const Point &og);
		float		getX(void);
		float		getY(void);
		~Point(void);
};

#endif
