#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface
{
	private:
		char * FPS;

		void setInterfaceOn();
		void setInterfaceOff();
		void drawFPS();
	public:
		Interface(void);
		~Interface(void);
		void getFPS(char * fps);
		void draw();
};

#endif
