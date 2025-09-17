#include "../Point.hpp"

//CONSTRUCTORS

Point::Point(void): _x(), _y()
{
}

Point::Point(float x, float y): _x(x), _y(y)
{
}

Point::Point(Point &og)
{
	*this = og;
}

//DESTRUCTORS

Point::~Point(void)
{//Potser he de fer delete als Fixeds
}

//OVERLOADS

Point	&Point::operator=(Point &og)
{
	return (og);
}

//GETTERS

float	Point::getX(void)
{
	return (this->_x.toFloat());
}

float	Point::getY(void)
{
	return (this->_y.toFloat());
}

//FUNCTIONS

void	Point::print(void)
{
	std::cout << "x:" << getX() << " y:" << getY() << std::endl;
}
