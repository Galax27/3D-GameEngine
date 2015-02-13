#ifndef ENGINE_H_
#define ENGINE_H_

class Engine
{
	private:
		long * frame, * time1, * time2;
		bool * keys;

		Keyboard * playerKeys;
		Interface * interf;
		Player * player;
		Camera * camera;
		Surface ** surface;

		void drawAxes(void);
		void calculateFPS(void);
		void turnCamera(double value);
		void zoomCamera(double value);
		void moveX(double value);
		void moveY(double value);
		void initPlayer(void);
		void interaction(void);
		void checkKeys(void);
	public:
		Engine();
		~Engine();
		void drawObjects();
		void setKey(int index, bool value);
};

#endif
