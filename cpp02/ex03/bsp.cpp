#include "Point.hpp"

static Fixed areaCalc( Point const a, Point const b, Point const c){
	Fixed res = 0.5f * std::fabs((a.getxValue() * (b.getyValue() - c.getyValue())) + 
						(b.getxValue() * (c.getyValue() - a.getyValue())) + 
						(c.getxValue() * (a.getyValue() - b.getyValue())));
	return (res);
}

bool isPointEdge(Fixed *areas){
	int i = 0;
	int count = 0;
	while (i < 3){
		if (areas[i] == 0){
			count += 1;
		}
		i++;
	}
	return (count == 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed totalArea = areaCalc(a, b, c);
	Fixed areaPoint1 = areaCalc(point, b, c);
	Fixed areaPoint2 = areaCalc(a, point, c);
	Fixed areaPoint3 = areaCalc(a, b, point);
	Fixed *areas = new Fixed[3];
	areas[0] = areaPoint1;
	areas[1] = areaPoint2;
	areas[2] = areaPoint3;
	if (isPointEdge(areas)){
		return (false);
	}
	std::cout << "area" << std::endl;
	std::cout << (areaPoint1 + areaPoint2 + areaPoint3) << std::endl;
	std::cout << totalArea << std::endl;
	std::cout << "area" << std::endl;
	return (totalArea == (areaPoint1 + areaPoint2 + areaPoint3));
}
