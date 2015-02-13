#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
	private:
		double * SX, * SY, * SZ, * X, * Y, * Z;
	public:
		~Object(void);
		Object(double sx = 0, double sy = 0, double sz = 0);
		double GetX(void);
		double GetY(void);
		double GetZ(void);
		double GetSX(void);
		double GetSY(void);
		double GetSZ(void);
		void SetX(double value);
		void SetY(double value);
		void SetZ(double value);
		void SetSX(double value);
		void SetSY(double value);
		void SetSZ(double value);
		virtual void draw(void);
};

#endif
