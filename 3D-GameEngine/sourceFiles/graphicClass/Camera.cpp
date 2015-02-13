#include "..\..\mainHeader.h"

Camera::~Camera(void)
{
	if(distance) { delete distance; }
	if(angle) { delete angle; }
	if(eyeX) { delete eyeX; }
	if(eyeY) { delete eyeY; }
	if(eyeZ) { delete eyeZ; }
	if(Lx) { delete Lx; }
	if(Ly) { delete Ly; }
	if(Lz) { delete Lz; }
}
Camera::Camera(void)
{
	distance =  new double(16);
	angle = new double(0);
	eyeX = new double(* distance * cos(* angle));
	eyeY = new double(* distance * sin(* angle));
	eyeZ = new double(* distance);
	Lx = new double(0);
	Ly = new double(0);
	Lz = new double(0);
}
void Camera::lookAt(double x, double y, double z)
{
	* eyeX = (* distance) * cos(* angle) + x;
	* eyeY = (* distance) * sin(* angle) + y;
	* eyeZ = (* distance) + z;
	* Lx = x;
	* Ly = y;
	* Lz = z;
	updateCamera();
}
void Camera::turnAngle(double value)
{
	if(value > 0) 
	{ if(* angle < 6.28) 
	{ * angle = * angle + value; }
	else 
	{ * angle = 0; } }
	else
	{ if(* angle >= 0) 
	{ * angle = * angle + value; }
	else
	{ * angle = 6.28; } }
}
void Camera::zoomDistance(double value)
{
	if(value > 0)
	{ if(* distance < 20) { * distance += value; } }
	else
	{ if(* distance > 4) { * distance += value; } }
}
void Camera::updateCamera(void)
{
	gluLookAt(* eyeX, * eyeY, * eyeZ, * Lx, * Ly, * Lz, 0, 0, 1);
}
double Camera::getAngle(void)
{
	return * angle;
}
