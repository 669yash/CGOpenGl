#include<iostream>
#include <gl/glut.h>
using namespace std;

int x1, y1, x2, y2;
void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-250, 250, -250, 250,-250,250);

}

void draw_pixel(int x, int y) {
    glPointSize(1);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	//outer square
	draw_line(-200, 200, 200, 200);
	draw_line(200, 200, 200, -200);
	draw_line(200, -200, -200, -200);
	draw_line(-200, -200, -200, 200);

	//Diamond
    draw_line(-200, 0, 0, 200);
	draw_line(0, 200, 200, 0);
	draw_line(200, 0, 0, -200);
	draw_line(0, -200, -200, 0);

	//Inner Square

	draw_line(-100, 100, 100, 100);
	draw_line(100, 100, 100, -100);
	draw_line(100, -100, -100, -100);
	draw_line(-100, -100, -100, 100);




	glFlush();
}

int main(int argc, char **argv) {




	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}