#ifndef CAMERA_H_
#define CAMERA_H_

class Camera  
{
	private:
		double * distance, * angle, * eyeX, * eyeY, * eyeZ, * Lx, * Ly, * Lz;
	public:
		~Camera(void);
		Camera(void);
		void lookAt(double x, double y, double z);
		void turnAngle(double value);
		void zoomDistance(double value);
		void updateCamera(void);
		double getAngle(void);
};

#endif
