#include "..\..\mainHeader.h"

Surface::~Surface() 
{
	if(R) { delete R; }
	if(G) { delete G; }
	if(B) { delete B; }
}
Surface::Surface(double sx, double sy, double sz) : Object(sx, sy, sz) 
{ 
	R = new double(0);
	G = new double(0);
	B = new double(0);
}
void Surface::setColor(double r, double g, double b)
{
	if(r < 0) { r = r * -1; if(r > 1) { r = r / 1000; } } * R = r;
	if(g < 0) { g = g * -1; if(g > 1) { g = g / 1000; } } * G = g;
	if(b < 0) { b = b * -1; if(b > 1) { b = b / 1000; } } * B = b;
}
void Surface::draw(void)
{
	glPushMatrix();
		glColor4f(* R, * G, * B, 0);
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
}
void Surface::interact(Player * & player)
{
	double limit = 2 * player->GetxyS();
	double limit2 = 2 * player->GetzS();
	bool x1, x2, y1, y2, z1, z2;
	x1 = (player->GetX() - player->GetSX() / 2) < (GetX() + GetSX() / 2);
	x2 = (player->GetX() + player->GetSX() / 2) > (GetX() - GetSX() / 2);
	y1 = (player->GetZ() - player->GetSZ() / 2) < (GetZ() + GetSZ() / 2);
	y2 = (player->GetZ() + player->GetSZ() / 2) > (GetZ() - GetSZ() / 2);
	z1 = (player->GetY() - player->GetSY() / 2) > (GetY() + GetSY() / 2);
	z2 = (player->GetY() - player->GetSY() / 2) < (GetY() + GetSY() / 2 + limit);
	if(x1 && x2 && y1 && y2 && z1 && z2) 
	{ player->SetY(GetY() + GetSY() / 2 + limit + player->GetSY() / 2); }

	x1 = (player->GetX() - player->GetSX() / 2) < (GetX() + GetSX() / 2);
	x2 = (player->GetX() + player->GetSX() / 2) > (GetX() - GetSX() / 2);
	y1 = (player->GetZ() - player->GetSZ() / 2) < (GetZ() + GetSZ() / 2);
	y2 = (player->GetZ() + player->GetSZ() / 2) > (GetZ() - GetSZ() / 2);
	z1 = (player->GetY() + player->GetSY() / 2) < (GetY() - GetSY() / 2);
	z2 = (player->GetY() + player->GetSY() / 2) > (GetY() - GetSY() / 2 - limit);
	if(x1 && x2 && y1 && y2 && z1 && z2)
	{ player->SetY(GetY() - GetSY() / 2 - limit - player->GetSY() / 2); }

	x1 = (player->GetY() - player->GetSY() / 2) < (GetY() + GetSY() / 2);
	x2 = (player->GetY() + player->GetSY() / 2) > (GetY() - GetSY() / 2);
	y1 = (player->GetZ() - player->GetSZ() / 2) < (GetZ() + GetSZ() / 2);
	y2 = (player->GetZ() + player->GetSZ() / 2) > (GetZ() - GetSZ() / 2);
	z1 = (player->GetX() - player->GetSX() / 2) > (GetX() + GetSX() / 2);
	z2 = (player->GetX() - player->GetSX() / 2) < (GetX() + GetSX() / 2 + limit);
	if(x1 && x2 && y1 && y2 && z1 && z2)
	{ player->SetX(GetX() + GetSX() / 2 + limit + player->GetSX() / 2); }

	x1 = (player->GetY() - player->GetSY() / 2) < (GetY() + GetSY() / 2);
	x2 = (player->GetY() + player->GetSY() / 2) > (GetY() - GetSY() / 2);
	y1 = (player->GetZ() - player->GetSZ() / 2) < (GetZ() + GetSZ() / 2);
	y2 = (player->GetZ() + player->GetSZ() / 2) > (GetZ() - GetSZ() / 2);
	z1 = (player->GetX() + player->GetSX() / 2) < (GetX() - GetSX() / 2);
	z2 = (player->GetX() + player->GetSX() / 2) > (GetX() - GetSX() / 2 - limit);
	if(x1 && x2 && y1 && y2 && z1 && z2)
	{ player->SetX(GetX() - GetSX() / 2 - limit - player->GetSX() / 2); }

	x1 = (player->GetY() - player->GetSY() / 2) < (GetY() + GetSY() / 2);
	x2 = (player->GetY() + player->GetSY() / 2) > (GetY() - GetSY() / 2);
	y1 = (player->GetX() - player->GetSX() / 2) < (GetX() + GetSX() / 2);
	y2 = (player->GetX() + player->GetSX() / 2) > (GetX() - GetSX() / 2);
	z1 = (player->GetZ() - player->GetSZ() / 2) > (GetZ() + GetSZ() / 2);
	z2 = (player->GetZ() - player->GetSZ() / 2) < (GetZ() + GetSZ() / 2 + limit2);
	if(x1 && x2 && y1 && y2 && z1 && z2) 
	{ player->SetZ(GetZ() + GetSZ() / 2 + limit2 + player->GetSZ() / 2); }
}
