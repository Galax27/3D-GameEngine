#include "..\..\mainHeader.h"

Player::~Player(void)
{
	if(xyS) { delete xyS; }
	if(zS)  { delete zS; }
}
Player::Player(double sx, double sy, double sz) : Object(sx, sy, sz) 
{
	xyS = new double(0);
	zS = new double(0);
}
void Player::SetxyS(double value) { * xyS = value; }
void Player::SetzS(double value) { * zS = value; }
double Player::GetxyS(void) { return * xyS; }
double Player::GetzS(void) { return * zS; }
void Player::draw(void)
{
	glPushMatrix();
		glColor3f(0.3, 1.0, 0.3);
		glBegin(GL_QUADS);
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
					
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
					
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);

			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);

			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);

			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
		glEnd();

		glColor3f(1, 1, 1);
		glLineWidth(2);
		glBegin(GL_LINES);
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);

			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);

			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);

			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
																				  
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
																				  
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);

			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
																				  
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);

			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);

			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() - GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);

			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() - GetSY() / 2, GetZ() + GetSZ() / 2);

			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() - GetSZ() / 2);
			glVertex3f(GetX() + GetSX() / 2, GetY() + GetSY() / 2, GetZ() + GetSZ() / 2);
		glEnd();
		glLineWidth(1);
	glPopMatrix();
	//glLineWidth(1);
}
