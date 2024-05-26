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
	/*
	glBegin(GL_POINTS);
	//for (ang = 0.0f; ang < 2 * GL_PI; ang += 2*GL_PI/6){
	for (ang = 0.0f; ang < 2 * M_PI; ang += 2*M_PI/6){
		x = radio * sin(ang);
		y = radio * cos(ang);
		glVertex2f(x,y);
	}
	glEnd();
	*/



    /*
	glBegin(GL_LINES);
	int num_segmentos = 4; // Numero de lineas
    for (int i = 0; i < num_segmentos; i++) {
        float angulo_actua = 2 * M_PI * i / num_segmentos; // ángulo actual
        float angulo_siguiente = 2 * M_PI * ((i + 1) % num_segmentos) / num_segmentos; // ángulo siguiente
        float cx1 = x + radio * cos(angulo_actua); // coordenada x del punto actual
        float cy1 = y +radio * sin(angulo_actua); // coordenada y del punto actual
        float cx2 = x + radio * cos(angulo_siguiente); // coordenada x del punto siguiente
        float cy2 = y + radio * sin(angulo_siguiente); // coordenada y del punto siguiente
        glVertex2f(cx1, cy1); // vértice actual
        glVertex2f(cx2, cy2); // vértice siguiente
    }
    glEnd();
    */

    /*
	glBegin(GL_LINE_STRIP); // No cierra el bucle
	int num_segmentos = 4; // Numero de lineas
    for (int i = 0; i <= num_segmentos; i++) { // Usamos <= para cerrar el círculo
        float angulo = 2 * M_PI * i / num_segmentos; // ángulo actual
        float cx = x + radio * cos(angulo); // coordenada x del punto
        float cy = y + radio * sin(angulo); // coordenada y del punto
        glVertex2f(cx, cy); // output del vértice
    }
    glEnd();
    */

    /*
	glBegin(GL_LINE_LOOP); // Sí cierra el bucle
	int num_segmentos = 4; // Numero de lineas
	for(int i = 0; i <= num_segmentos; i++) {
        float angulo = 2.0 * M_PI * i / num_segmentos; // ángulo actual
        float cx = x + radio * cos(angulo); // coordenada x del punto
        float cy = y + radio * sin(angulo); // coordenada y del punto
        glVertex2f(cx, cy); // output del vértice
    }
    glEnd();
    */

    /*
    glBegin(GL_LINE_STRIP);
    int num_cuadrantes = 2;
    float delta_angulo = 0.1;
    float A = 1.0;
    float B = 0.2;
    */
    // ecuación paramétrica A + B * angulo
    /*
    for (float angulo = num_cuadrantes * M_PI / 2.0; angulo >= 0; angulo -= delta_angulo) {
        float r = A + B * angulo;
        float x = r * cos(angulo);
        float y = r * sin(angulo);
        glVertex2f(x, y);
    }
    */

    /*
    for (float angulo = 0; angulo <= num_cuadrantes * M_PI / 2.0; angulo += delta_angulo) {
        float r = A + B * angulo;
        float x = r * cos(angulo);
        float y = r * sin(angulo);
        glVertex2f(x, y);
    }
    glEnd();
    */


    // Ejes




    /*
    // Sin nudo izquierda

    */

    /*
    // Sin nudo hacia abajo

    */

    /*
    // Con nudo hacia la derecha
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float r = 100 * (0.5 + cos(t));
            float x = r * cos(t);
            float y = r * sin(t);
            glVertex2f(x, y);
        }
    glEnd();
    */

    /*
    // Con nudo hacia la izquierda
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float r = 100 * (0.5 + cos(t));
            float x = r * cos(t);
            float y = r * sin(t);
            glVertex2f(-x, y);
        }
    glEnd();
    */

/*
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float r = 100 * cos(5*t);
            float x = r * cos(t);
            float y = r * sin(t);
            glVertex2f(x, y);
        }
    glEnd();
*/


    dibujarEjes();
    //dibujarCardioideHorizontalIzquierda();
    //dibujarCardioideVerticalAbajo();
    //dibujarCaracolPascalHorizontalDerecha();
    //dibujarCaracolPascalHorizontalIzquierda();
    dibujarRosaPolar();

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
