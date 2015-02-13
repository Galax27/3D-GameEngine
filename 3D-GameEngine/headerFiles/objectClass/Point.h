#ifndef POINT_H_
#define POINT_H_

class Point
{
	private:
		double * X, * Y, * Z;
	public:
		~Point(void);
		Point(void);
		Point(double x, double y, double z);
		void setX(double x);
		void setY(double y);
		void setZ(double z);
		double getX(void);
		double getY(void);
		double getZ(void);
};

#endif
