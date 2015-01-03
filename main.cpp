#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
double index = 0; double ang = 0;
class Point
{
	private:
		double * X, * Y, * Z;
	public:
		~Point(void)
		{
			if(X)	{ delete X; }
			if(Y)	{ delete Y; }
			if(Z)	{ delete Z; }
		}
		Point(void)
		{
			X = new double(0);
			Y = new double(0);
			Z = new double(0);
		}
		Point(double x, double y, double z)
		{
			X = new double(x);
			Y = new double(y);
			Z = new double(z);
		}
		void setX(double x) { * X = x; }
		void setY(double y) { * Y = y; }
		void setZ(double z) { * Z = z; }
		double getX(void)	{ return * X; }
		double getY(void)	{ return * Y; }
		double getZ(void)	{ return * Z; }
};
class Object
{
	private:
		double * SX, * SY, * SZ, * X, * Y, * Z;
	public:
		~Object(void)
		{
			if(SX) { delete SX; }
			if(SY) { delete SY; }
			if(SZ) { delete SZ; }
			if(X) { delete X; }
			if(Y) { delete Y; }
			if(Z) { delete Z; }
		}
		Object(double sx = 0, double sy = 0, double sz = 0)
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
		double GetX(void) { return * X; }
		double GetY(void) { return * Y; }
		double GetZ(void) { return * Z; }
		double GetSX(void) { return * SX; }
		double GetSY(void) { return * SY; }
		double GetSZ(void) { return * SZ; }
		void SetX(double value)	{ * X = value; }
		void SetY(double value)	{ * Y = value; }
		void SetZ(double value)	{ * Z = value; }
		void SetSX(double value) { * SX = value; }
		void SetSY(double value) { * SY = value; }
		void SetSZ(double value) { * SZ = value; }
		virtual void draw(void) { }
};
class Player : public Object
{
	private:
		double * xyS, * zS;
	public:
		~Player(void)
		{
			if(xyS) { delete xyS; }
			if(zS)  { delete zS; }
		}
		Player(double sx, double sy, double sz) : Object(sx, sy, sz) 
		{
			xyS = new double(0);
			zS = new double(0);
		}
		void SetxyS(double value) { * xyS = value; }
		void SetzS(double value) { * zS = value; }
		double GetxyS(void) { return * xyS; }
		double GetzS(void) { return * zS; }
		void draw(void)
		{
			glPushMatrix();
				glColor3f(0.3, 1.0, 0.3);
				/*glTranslatef(GetX(), GetY(), GetZ());
				//glRotatef(ang * 180 / 3.14, 0, 0, 1);
				glutWireCube(GetSX());*/
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
};
class Surface : public Object
{
	private:
		double * R, * G, * B;
	public:
		~Surface() 
		{
			if(R) { delete R; }
			if(G) { delete G; }
			if(B) { delete B; }
		}
		Surface(double sx = 0, double sy = 0, double sz = 0) : Object(sx, sy, sz) 
		{ 
			R = new double(0);
			G = new double(0);
			B = new double(0);
		}
		void setColor(double r, double g, double b)
		{
			if(r < 0) { r = r * -1; if(r > 1) { r = r / 1000; } } * R = r;
			if(g < 0) { g = g * -1; if(g > 1) { g = g / 1000; } } * G = g;
			if(b < 0) { b = b * -1; if(b > 1) { b = b / 1000; } } * B = b;
		}
		void draw(void)
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
		void interact(Player * & player)
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
};
class Camera  
{
	private:
		double * distance, * angle, * eyeX, * eyeY, * eyeZ, * Lx, * Ly, * Lz;
	public:
		~Camera()
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
		Camera()
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
		void lookAt(double x, double y, double z)
		{
			* eyeX = (* distance) * cos(* angle) + x;
			* eyeY = (* distance) * sin(* angle) + y;
			* eyeZ = (* distance) + z;
			* Lx = x;
			* Ly = y;
			* Lz = z;
			updateCamera();
		}
		void turnAngle(double value)
		{
			if(value > 0) 
			{ if(* angle < 6.28) 
			{ * angle = * angle + value; ang += 0.002; }
			else 
			{ * angle = 0; ang = 0; } }
			else
			{ if(* angle >= 0) 
			{ * angle = * angle + value; ang -= 0.002; }
			else
			{ * angle = 6.28; ang = 6.28; } }
		}
		void zoomDistance(double value)
		{
			if(value > 0)
			{ if(* distance < 20) { * distance += value; } }
			else
			{ if(* distance > 4) { * distance += value; } }
		}
		void updateCamera(void)
		{
			gluLookAt(* eyeX, * eyeY, * eyeZ, * Lx, * Ly, * Lz, 0, 0, 1);
		}
		double getAngle(void)
		{
			return * angle;
		}
};
class Buttons
{
	private:
		char * keys;
		
		void loadDefault(void)
		{
			keys[0] = 'e';
			keys[1] = 's';
			keys[2] = 'd';
			keys[3] = 'f';
			keys[4] = ' ';
		}
	public:
		~Buttons()
		{
			if(keys) { delete keys; }
		}
		Buttons()
		{
			keys = new char[5];
			loadDefault();
		}
		int keyUp(void)		{ return keys[0]; }
		int keyLeft(void)	{ return keys[1]; }
		int keyDown(void)	{ return keys[2]; }
		int keyRight(void)	{ return keys[3]; }
		int keyJump(void)	{ return keys[4]; }
		void setKey(int index, int newKey) { keys[index] = newKey; }
};
class GameInterface
{
	private:
		char * FPS;

		void setInterfaceOn()
		{
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0, 800, 600, 0);
			glMatrixMode(GL_MODELVIEW);

			glPushMatrix();
			glLoadIdentity();
		}
		void setInterfaceOff()
		{
			glPopMatrix();

			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		}
		void drawFPS()
		{
			glColor3f(1, 1, 1);
			glRasterPos3f(20, 20, 0);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
			for(char * c = FPS; *c != '\0'; c++) { glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); }
		}
	public:
		GameInterface() { FPS = new char[10]; strcpy(FPS,"0.00"); }
		~GameInterface() { if(FPS) { delete FPS; } }
		void getFPS(char * fps) { if(fps) { strncpy(FPS, fps, 9); } }
		void draw() { setInterfaceOn(); drawFPS(); setInterfaceOff(); }
};
class gameEngine
{
	private:
		long * frame, * time1, * time2;
		bool * keys;

		Buttons * playerKeys;
		GameInterface * interf;
		Player * player;
		Camera * camera;
		Surface ** surface;

		void drawAxes(void)
		{
			glPushMatrix();
				glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(-10000, 0, 0);
					glVertex3f(10000, 0, 0);
				glEnd();
				glBegin(GL_LINES);
					glColor3f(0, 1, 0);
					glVertex3f(0, -10000, 0);
					glVertex3f(0, 10000, 0);
				glEnd();
				glBegin(GL_LINES);
					glColor3f(0, 0, 1);
					glVertex3f(0, 0, -10000);
					glVertex3f(0, 0, 10000);
				glEnd();
			glPopMatrix();
		}
		void calculateFPS(void)
		{
			char * fps = new char[10];
			* frame = * frame + 1;
			* time1 = glutGet(GLUT_ELAPSED_TIME);
			if (* time1 - * time2 > 1000) 
			{
				sprintf(fps, "%4.2f", (* frame) * 1000.0 / (* time1 - * time2));
				* time2 = * time1;
				* frame = 0;
				interf->getFPS(fps);
			}
			delete fps;
		}
		void turnCamera(double value) { camera->turnAngle(value); }
		void zoomCamera(double value) { camera->zoomDistance(value); }
		void moveX(double value) { player->SetX(player->GetX() + value); }
		void moveY(double value) { player->SetY(player->GetY() + value); }
		void initPlayer(void)
		{
			player->SetX(5);		player->SetY(5);		player->SetZ(10);	player->SetxyS(0.01);	player->SetzS(0.05);
		}
		void interaction(void) { for(int i = 0; i < 3; i++) { surface[i]->interact(player); } }
		void checkKeys(void)
		{
			if(keys['r']) { initPlayer(); }
			if(keys['4']) { turnCamera(0.002); }
			if(keys['5']) { zoomCamera(0.01); }
			if(keys['6']) { turnCamera(-0.002); }
			if(keys['8']) { zoomCamera(-0.01); }
			if(keys[playerKeys->keyUp()])	{ moveX(player->GetxyS()); }
			if(keys[playerKeys->keyDown()]) { moveX(-player->GetxyS()); }
			if(keys[playerKeys->keyLeft()]) { moveY(player->GetxyS()); }
			if(keys[playerKeys->keyRight()]){ moveY(-player->GetxyS()); }
			if(keys[playerKeys->keyJump()]) { index = player->GetZ() + 5; }
			if(index - player->GetZ() > 0.01) 
			{ player->SetZ(player->GetZ() + player->GetzS()); index-=0.05; }
			else
			{player->SetZ(player->GetZ() - player->GetzS());}
		}
	public:
		gameEngine()
		{
			frame = new long(0);
			time1 = new long(0);
			time2 = new long(0);

			keys = new bool[256]; for(int i = 0; i < 256; i++) { keys[i] = false; }

			player = new Player(1, 1, 3);
			initPlayer();

			camera = new Camera();

			surface = new Surface*[3];
			surface[0] = new Surface(10, 30, 4.0);
			surface[0]->SetX(5);		surface[0]->SetY(15);	surface[0]->SetZ(0);		surface[0]->setColor(0.0, 0.5, 0.5);
			surface[1] = new Surface(30, 10, 0.0);
			surface[1]->SetX(15);	surface[1]->SetY(35);	surface[1]->SetZ(0);		surface[1]->setColor(0.3, 0.5, 0.5);
			surface[2] = new Surface(6, 1, 6);
			surface[2]->SetX(5);		surface[2]->SetY(5);		surface[2]->SetZ(3);		surface[2]->setColor(0.5, 0.5, 0.0);

			playerKeys = new Buttons();
			interf = new GameInterface();
		}
		~gameEngine()
		{
			if(frame)  { delete frame; }
			if(time1)  { delete time1; }
			if(time2)  { delete time2; }
			if(keys)   { delete keys; }
			if(player) { delete player; }
			if(camera) { delete camera; }
			if(interf) { delete interf; }
			if(surface) { for(int i = 0; i < 3; i++) { delete surface[i]; } delete surface; }
		}
		void drawObjects()
		{
			checkKeys();
			interaction();

			camera->lookAt(player->GetX(), player->GetY(), player->GetZ());
			
			drawAxes();
			player->draw();
			
			for(int i = 0; i < 3; i++) { surface[i]->draw(); }

			calculateFPS();
			interf->draw();
		}
		void setKey(int index, bool value) { keys[index] = value; }
};

static gameEngine * g = NULL;

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	(*g).drawObjects();

	glutSwapBuffers();
	glutPostRedisplay();
}
void Reshape(int w, int h)
{
	if(h == 0) { h = 1; }
	float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}
void KeyboardPress(unsigned char key, int x, int y) { g->setKey(key, true); }
void KeyboardRelease(unsigned char key, int x, int y) { g->setKey(key, false); }
class openGL
{
	private:
		void setDrawFunction(void(*functionName)())
		{
			glutDisplayFunc((*functionName));
		}
		void setIdleFunction(void(*functionName)())
		{
			glutIdleFunc((*functionName));
		}
		void setReshapeFunction(void(*functionName)(int,int))
		{
			glutReshapeFunc((*functionName));
		}
		void setKeyDownFunction(void(*functionName)(unsigned char, int, int))
		{
			glutKeyboardFunc((*functionName));
		}
		void setKeyUpFunction(void(*functionName)(unsigned char, int, int))
		{
			glutKeyboardUpFunc((*functionName));
		}
		void setBackground(double red, double green, double blue, double alpha)
		{
			glEnable(GL_DEPTH_TEST);
			glClearColor(red, green, blue, alpha);
		}
		void setWindow()
		{
			setDrawFunction(Display);
			setIdleFunction(Display);
			setReshapeFunction(Reshape);
			setKeyDownFunction(KeyboardPress);
			setKeyUpFunction(KeyboardRelease);
			setBackground(0,0,0,0);
			glewInit();
		}
	public:
		~openGL()
		{
			if(g) { delete g; }
		}
		openGL(int argc, char ** argv)
		{
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
			glutInitWindowPosition(100, 100);
			glutInitWindowSize(800, 600);
			glutCreateWindow("Engine V-15.01.02");

			setWindow();

			g = new gameEngine();
		}
		void run()
		{
			glutMainLoop();
		}
};
int main(int argc, char ** argv) { openGL program(argc,argv); program.run(); return 0; }
