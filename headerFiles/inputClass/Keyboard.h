#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard
{
	private:
		char * key;
		
		void loadDefault(void);
	public:
		~Keyboard(void);
		Keyboard(void);
		int keyUp(void);
		int keyLeft(void);
		int keyDown(void);
		int keyRight(void);
		int keyJump(void);
		void setKey(int index, int newKey);
};

#endif
