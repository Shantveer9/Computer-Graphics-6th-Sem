#include<GL/glut.h>
#include<stdio.h>
GLfloat mat_ambient[] = { 0.7,0.7,0.7,1.0 };
GLfloat mat_diffuse[] = { 0.5,0.5,0.5,1.0 };
GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
const  GLfloat mat_shininess[] = { 50.0 };
GLfloat light_intensity[] = { 0.7,0.7,0.7,1.0 };
GLfloat light_position[] = { 2.0,6.0,3.0,0.0 };

void init() {

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_intensity);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0, 1.0, 2.0, 0.0, 0.2, 0.2, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void teapot() {
	glPushMatrix();
	glTranslated(0.4, 0.0, 0.4);
	glRotated(30, 0, 1, 0);
	glutSolidTeapot(0.2);
	glPopMatrix();
}

void tabletop()
{

	glPushMatrix();
	glTranslated(0.0, -0.3, 0.0);
	glScaled(7.0, 0.5, 7.0);
	glutSolidCube(0.2);
	glPopMatrix();
}

void frontleg() {
	glPushMatrix();
	glTranslated(0.5, -0.7, 0.5);
	glScaled(0.5, 7.0, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void leftleg() {
	glPushMatrix();
	glTranslated(-0.5, -0.7, 0.5);
	glScaled(0.5, 7.0, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}

void rightleg()
{
	glPushMatrix();
	glTranslated(0.5, -0.7, -0.5);
	glScaled(0.5, 7.0, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}
void backleg()
{
	glPushMatrix();
	glTranslated(-0.5, -0.7, -0.5);
	glScaled(0.5, 7.0, 0.5);
	glutSolidCube(0.1);
	glPopMatrix();
}
void leftwall()
{
	glPushMatrix();
	glTranslated(-1.0, -0.0, 0.0);
	glScaled(0.1, 10.0, 10.0);
	glutSolidCube(0.2);
	glPopMatrix();
}
void bottomfloor()
{
	glPushMatrix();
	glTranslated(0.0, -1.0, 0.0);
	glScaled(10.1, 0.1, 10.0);
	glutSolidCube(0.2);
	glPopMatrix();
}

void rightwall()
{
	glPushMatrix();
	glTranslated(0.0, 0.0, -1.0);
	glScaled(10.0, 10.0, 0.1);
	glutSolidCube(0.2);
	glPopMatrix();
}

void drawText(float x, float y, const char* s) {
	int i;
	glRasterPos2f(x, y);
	for (i = 0; s[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	teapot();
	tabletop();
	frontleg();
	leftleg();
	rightleg();
	backleg();
	bottomfloor();
	rightwall();
	leftwall();
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);
	drawText(0, 1.8, "Tea Pot");
	drawText(0.9, 1.8, "Prajwal.P");
	drawText(0.9, 1.7, "BATCH: B4");
	drawText(0.9, 1.6, "USN: 1BI17CS111");
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(400, 300);
	glutCreateWindow("shaded Scene");
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glViewport(0, 0, 640, 480);
	glutMainLoop();
}  