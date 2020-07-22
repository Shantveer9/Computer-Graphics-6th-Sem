#include<stdio.h>
#include<math.h>
#include<iostream>
#include<Windows.h>
#include<GL/glut.h>
int le[500], re[500], flag = 0, m;

void init()
{
	gluOrtho2D(0, 500, 0, 500);
}

void edge(int x0, int y0, int x1, int y1)
{
	if (y1 < y0)
	{
		int tmp;
		tmp = y1;
		y1 = y0;
		y0 = tmp;
		tmp = x1;
		x1 = x0;
		x0 = tmp;
	}
	int x = x0;
	m = (y1 - y0) / (x1 - x0);
	for (int i = y0; i < y1; i++)
	{
		if (x < le[i])
			le[i] = x;
		if (x > re[i])
			re[i] = x;
		x += (1 / m);
	}
}

void draw_text(float x, float y, const char* s)
{
	int i;
	glRasterPos2f(x, y);
	for (i = 0; s[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(200, 100);
	glVertex2f(100, 200);
	glVertex2f(200, 300);
	glVertex2f(300, 200);
	glEnd();
	for (int i = 0; i < 500; i++)
	{
		le[i] = 500;
		re[i] = 0;
	}
	edge(200, 100, 100, 200);
	edge(100, 200, 200, 300);
	edge(200, 300, 300, 200);
	edge(300, 200, 200, 100);
	if (flag == 1)
	{
		for (int i = 0; i < 500; i++)
		{
			if (le[i] < re[i])
			{
				for (int j = le[i]; j < re[i]; j++)
				{
					//Sleep(1);
					glColor3f(1, 0, 0);
					glBegin(GL_POINTS);
					glVertex2f(j, i);
					glEnd();
				}
			}
		}
	}
	draw_text(200.0, 400.0, "Polygon filling using Scan Line Algorithm");
	draw_text(200.0, 390.0, "Prajwal.P");
	draw_text(200.0, 380.0, "1BI17CS111");
	draw_text(200.0, 370.0, "Batch: B4");
	glFlush();
}

void ScanMenu(int id)
{
	if (id == 1) {
		flag = 1;
	}
	else if (id == 2) {
		flag = 0;
	}
	else { exit(0); }
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Scan Line Algorithm");
	init();
	glutDisplayFunc(display);
	glutCreateMenu(ScanMenu);
	glutAddMenuEntry("scanfill", 1);
	glutAddMenuEntry("clear", 2);
	glutAddMenuEntry("exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
