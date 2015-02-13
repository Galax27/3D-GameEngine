#include "..\..\mainHeader.h"

Point::~Point(void)
{
	if(X)	{ delete X; }
	if(Y)	{ delete Y; }
	if(Z)	{ delete Z; }
}
Point::Point(void)
{
	X = new double(0);
	Y = new double(0);
	Z = new double(0);
}
Point::Point(double x, double y, double z)
{
	X = new double(x);
	Y = new double(y);
	Z = new double(z);
}
void Point::setX(double x)	{ * X = x; }
void Point::setY(double y)	{ * Y = y; }
void Point::setZ(double z)	{ * Z = z; }
double Point::getX(void)	{ return * X; }
double Point::getY(void)	{ return * Y; }
double Point::getZ(void)	{ return * Z; }
