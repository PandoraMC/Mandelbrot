#include<GL/glut.h>
#include<complex.h>

void dibujo(void);

_Complex centro = 2*640/3 + 480/2*I;

int main(int argN, char** argV){
	glutInit(&argN, argV);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mandelbrot");
	glClearColor(0., 0., 0., 0.);
	gluOrtho2D(0., 640., 0., 480.);
	glutDisplayFunc(dibujo);
	glutMainLoop();
	return 0;
}

void dibujo(void){
	_Complex Zn, C;
	unsigned int n = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		for(unsigned int Y = 0; Y < 480; Y++){
			for(unsigned int X = 0; X < 640; X++){
				Zn = 0 + 0*I;
				n = 0;
				C = ((X + Y*I) - centro)/150;
				while(cabs(Zn) < 2 & n < 10){
					Zn = cpow(Zn, 6) + C;
					n++;
				}
				glColor3f((float)X/(640*2) + 0.5, n/10.0f, (float)Y/(2*480) + 0.5);
				glVertex2i(X, Y);
			}
		}
	glEnd();
	glFlush();
}
