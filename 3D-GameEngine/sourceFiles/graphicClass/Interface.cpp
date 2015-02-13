#include "..\..\mainHeader.h"

void Interface::setInterfaceOn()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 800, 600, 0);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glLoadIdentity();
}
void Interface::setInterfaceOff()
{
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void Interface::drawFPS()
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
Interface::Interface() 
{ 
	FPS = new char[10];
	strcpy(FPS,"0.00"); 
}
Interface::~Interface() 
{
	if(FPS) { delete FPS; } 
}
void Interface::getFPS(char * fps) 
{ 
	if(fps) { strncpy(FPS, fps, 9); }
}
void Interface::draw() 
{
	setInterfaceOn(); 
	drawFPS(); 
	setInterfaceOff();
}
