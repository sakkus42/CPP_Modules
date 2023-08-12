#include "Fixed.hpp"

class Point{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(float x, float y);
		Point(Point const& point);
		~Point();

		Point&	operator=(Point const& point);

		float	getxValue() const;
		float	getyValue() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);