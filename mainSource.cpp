#include "mainHeader.h"

static Engine * g = NULL;

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	(*g).drawObjects();

	glutSwapBuffers();
	glutPostRedisplay();
}
void Reshape(int w, int h)
{
	if(h == 0) { h = 1; }
	float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}
void KeyboardPress(unsigned char key, int x, int y) { g->setKey(key, true); }
void KeyboardRelease(unsigned char key, int x, int y) { g->setKey(key, false); }
class openGL
{
	private:
		void setDrawFunction(void(*functionName)())
		{
			glutDisplayFunc((*functionName));
		}
		void setIdleFunction(void(*functionName)())
		{
			glutIdleFunc((*functionName));
		}
		void setReshapeFunction(void(*functionName)(int,int))
		{
			glutReshapeFunc((*functionName));
		}
		void setKeyDownFunction(void(*functionName)(unsigned char, int, int))
		{
			glutKeyboardFunc((*functionName));
		}
		void setKeyUpFunction(void(*functionName)(unsigned char, int, int))
		{
			glutKeyboardUpFunc((*functionName));
		}
		void setBackground(double red, double green, double blue, double alpha)
		{
			glEnable(GL_DEPTH_TEST);
			glClearColor(red, green, blue, alpha);
		}
		void setWindow()
		{
			setDrawFunction(Display);
			setIdleFunction(Display);
			setReshapeFunction(Reshape);
			setKeyDownFunction(KeyboardPress);
			setKeyUpFunction(KeyboardRelease);
			setBackground(0,0,0,0);
			glewInit();
		}
	public:
		~openGL()
		{
			if(g) { delete g; }
		}
		openGL(int argc, char ** argv)
		{
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
			glutInitWindowPosition(100, 100);
			glutInitWindowSize(800, 600);
			glutCreateWindow("Engine V-15.01.02");

			setWindow();

			g = new Engine();
		}
		void run()
		{
			glutMainLoop();
		}
};
int main(int argc, char ** argv) { openGL program(argc,argv); program.run(); return 0; }
