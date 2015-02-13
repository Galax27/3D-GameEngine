#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public Object
{
	private:
		double * xyS, * zS;
	public:
		~Player(void);
		Player(double sx, double sy, double sz);// : Object(sx, sy, sz);
		void SetxyS(double value);
		void SetzS(double value);
		double GetxyS(void);
		double GetzS(void);
		void draw(void);
};

#endif
