#ifndef _Game_h
#define _Game_h

#include "stdafx.h"
#include "glut.h"

#define FROM_RIGHT      1 
#define FROM_LEFT       2 
#define FROM_TOP        3 
#define FROM_BOTTOM     4 

static int WINDOW_WIDTH, WINDOW_HEIGHT;

struct RECTA
{
	float left, top, right, bottom;
};

RECTA wall;
RECTA player_1 = { 50, 750, 100, 800 };

float posX = 0;
float posY = 0;
float posZ = 0;

//exit on escape
void Exit(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}

//player movement - needs work
float move_unit = 10.0f;
void keyboardown(int key, int x, int y)
{
	switch (key){
	case GLUT_KEY_RIGHT:	
		posX += move_unit;		
		break;

	case GLUT_KEY_LEFT:
		posX -= move_unit;
		break;

	case GLUT_KEY_UP:
		posY -= move_unit;
		break;

	case GLUT_KEY_DOWN:
		posY += move_unit;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

//draw rectangles
void DrawRectangle(RECTA rect)
{
	glBegin(GL_QUADS);
	glVertex2f(rect.left, rect.bottom);
	glVertex2f(rect.right, rect.bottom);
	glVertex2f(rect.right, rect.top);
	glVertex2f(rect.left, rect.top);
	glEnd();
}

// OpenGL Setting
void Setting(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// OnWindowResize 
void Reshape(int w, int h)
{
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//GLut timer
void Timer(int v)
{
	glutTimerFunc(1, Timer, 1);
}
/*
*/
#endif