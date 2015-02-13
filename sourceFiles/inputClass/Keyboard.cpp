#include "..\..\mainHeader.h"

void Keyboard::loadDefault(void)
{
	key[0] = 'e';
	key[1] = 's';
	key[2] = 'd';
	key[3] = 'f';
	key[4] = ' ';
}
Keyboard::~Keyboard(void)
{
	if(key) { delete key; }
}
Keyboard::Keyboard(void)
{
	key = new char[5];
	loadDefault();
}
int Keyboard::keyUp(void)	{ return key[0]; }
int Keyboard::keyLeft(void)	{ return key[1]; }
int Keyboard::keyDown(void)	{ return key[2]; }
int Keyboard::keyRight(void){ return key[3]; }
int Keyboard::keyJump(void)	{ return key[4]; }
void Keyboard::setKey(int index, int newKey) { key[index] = newKey; }
