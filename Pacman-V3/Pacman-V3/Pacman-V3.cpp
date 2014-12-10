// Pacman-V3.cpp : Defines the entry point for the console application.
//http://stackoverflow.com/questions/13150393/opengl-2d-moving-and-object-by-1-unit
//http://codepad.org/ERyTZyYy


#include "stdafx.h"
#include "TextureReader.h"
#include "game.h"
#include "glut.h"

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	wall.left = wall.top = 0;
	wall.right = WINDOW_WIDTH;
	wall.bottom = WINDOW_HEIGHT;
	
	glTranslatef(posX, posY, posZ);
	DrawRectangle(player_1);
	glPopMatrix();
	glFlush();

	//game collision logic

	glutSwapBuffers();

}
void Init(){
	// set clear color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// set fill color to white
	glColor3f(1.0, 1.0, 1.0);

	/*char* blob = "C:\\Users\\Sizza\\Desktop\\blob.txt";
	TextureReader tx;
	tx(blob, 27, 21);*/

	//set up standard orthogonal view with clipping
	//box as cube of side 2 centered at origin
	//This is the default view and these statements could be removed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

}
int main(int argc, char** argv)
{
	int key = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simons Shitty Pacman Game");

	Setting();
	Init();

	glutDisplayFunc(Render);
	glutIdleFunc(Render);

	glutTimerFunc(1, Timer, 1);
	glutReshapeFunc(Reshape);

	glutKeyboardFunc(Exit);
	glutSpecialFunc(keyboardown);

	glutMainLoop();
	return 0;
}