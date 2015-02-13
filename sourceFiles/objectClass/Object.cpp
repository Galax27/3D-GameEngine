#include "..\..\mainHeader.h"

Object::~Object(void)
{
	if(SX) { delete SX; }
	if(SY) { delete SY; }
	if(SZ) { delete SZ; }
	if(X) { delete X; }
	if(Y) { delete Y; }
	if(Z) { delete Z; }
}
Object::Object(double sx, double sy, double sz)
{
	if(sx < 1) { sx = 1; }
	if(sy < 1) { sy = 1; }
	if(sz < 0) { sz = 0; }
	SX = new double(sx);
	SY = new double(sy);
	SZ = new double(sz);
	X = new double(0);
	Y = new double(0);
	Z = new double(0);
}
double Object::GetX(void) { return * X; }
double Object::GetY(void) { return * Y; }
double Object::GetZ(void) { return * Z; }
double Object::GetSX(void) { return * SX; }
double Object::GetSY(void) { return * SY; }
double Object::GetSZ(void) { return * SZ; }
void Object::SetX(double value)	{ * X = value; }
void Object::SetY(double value)	{ * Y = value; }
void Object::SetZ(double value)	{ * Z = value; }
void Object::SetSX(double value) { * SX = value; }
void Object::SetSY(double value) { * SY = value; }
void Object::SetSZ(double value) { * SZ = value; }
void Object::draw(void) { }
