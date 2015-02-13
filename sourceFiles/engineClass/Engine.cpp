#include "..\..\mainHeader.h"

void Engine::drawAxes(void)
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
void Engine::calculateFPS(void)
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
void Engine::turnCamera(double value) { camera->turnAngle(value); }
void Engine::zoomCamera(double value) { camera->zoomDistance(value); }
void Engine::moveX(double value) { player->SetX(player->GetX() + value); }
void Engine::moveY(double value) { player->SetY(player->GetY() + value); }
void Engine::initPlayer(void)
{
	player->SetX(5);		player->SetY(5);		player->SetZ(15);	player->SetxyS(0.01);	player->SetzS(0.02);
}
void Engine::interaction(void) { for(int i = 0; i < 3; i++) { surface[i]->interact(player); } }
void Engine::checkKeys(void)
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
	//if(keys[playerKeys->keyJump()]) { if(state == 0) { index = player->GetZ() + 10; } }
	//if(index - player->GetZ() > 0.02) 
	//{ player->SetZ(player->GetZ() + player->GetzS()); index-=player->GetzS(); }
	//else
	{ player->SetZ(player->GetZ() - player->GetzS()); }
}
Engine::Engine()
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

	playerKeys = new Keyboard();
	interf = new Interface();
}
Engine::~Engine()
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
void Engine::drawObjects()
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
void Engine::setKey(int index, bool value) { keys[index] = value; }
