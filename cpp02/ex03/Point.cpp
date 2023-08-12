#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Point const& point){
	this->x = point.x;
	this->y = point.y;
}

Point::~Point()
{
}

Point& Point::operator=(Point const& point){
	this->x = point.x;
	this->y = point.y;
	return (*this);
}

float	Point::getxValue() const{
	return (x.toFloat());
}

float	Point::getyValue() const{
	return (y.toFloat());
}
