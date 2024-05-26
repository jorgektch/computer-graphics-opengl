/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include "funciones.hpp"
#include <GL/glut.h>
#endif

//const int screenWidth = 640;
//const int screenHeight = 480;

void init(void);
void display(void);
void reshape(int,int);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	//glutInitWindowPosition(200,200);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
void init(void){
	glClearColor(0.0,0.0,0.0,0.0); //parametros: rojo, amarillo, azul, el cuarto es el parametro alpha
	glShadeModel(GL_FLAT);
}
void display(void){
	GLfloat ang, radio = 7.0f, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix(); // salva el estado actual de la matriz

    dibujarEjes();
    //dibujarCardioideHorizontalIzquierda();
    dibujarCardioideVerticalAbajo();
    //dibujarCaracolPascalHorizontalDerecha();
    //dibujarCaracolPascalHorizontalIzquierda();
    //dibujarRosaPolar();

	glPopMatrix(); // reecupera el estado del matriz
	glFlush();
}
void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-10.0,10.0,-10.0,10,-10.0,10.0);
    gluOrtho2D(-screenWidth / 2, screenWidth / 2, -screenHeight / 2, screenHeight / 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
