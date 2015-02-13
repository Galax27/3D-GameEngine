#ifndef SURFACE_H_
#define SURFACE_H_

class Surface : public Object
{
	private:
		double * R, * G, * B;
	public:
		~Surface(void);
		Surface(double sx = 0, double sy = 0, double sz = 0);
		void setColor(double r, double g, double b);
		void interact(Player *& p);
		void draw(void);
};

#endif
