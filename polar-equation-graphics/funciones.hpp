//#include <windows.h>
#include <GL/glut.h>

const int screenWidth = 640;
const int screenHeight = 480;

void dibujarEjes() {
    glColor3f(1.0, 1.0, 1.0); // Lineas blancas
    glBegin(GL_LINES);
        glVertex2f(-screenWidth / 2, 0);
        glVertex2f(screenWidth / 2, 0);
        glVertex2f(0, -screenHeight / 2);
        glVertex2f(0, screenHeight / 2);
    glEnd();
}

void dibujarCardioideHorizontalIzquierda() {
    glColor3f(1.0, 0.0, 0.0); // Figura roja
    float a = 100, b = 100;
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float radio = a * cos(t) + b;
            float x = radio * cos(t);
            float y = radio * sin(t);
            glVertex2f(-x, y);
        }
    glEnd();
}

void dibujarCardioideVerticalAbajo() {
    glColor3f(1.0, 0.0, 0.0); // Figura roja
    float a = 100, b = 100;
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float radio = a * cos(t) + b;
            float x = radio * cos(t);
            float y = radio * sin(t);
            glVertex2f(y, -x);
        }
    glEnd();
}

void dibujarCaracolPascalHorizontalDerecha() {
    glColor3f(1.0, 0.0, 0.0); // Figura roja
    float a = 100, b = 50;
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float radio = a * cos(t) + b;
            float x = radio * cos(t);
            float y = radio * sin(t);
            glVertex2f(x, y);
        }
    glEnd();
}

void dibujarCaracolPascalHorizontalIzquierda() {
    glColor3f(1.0, 0.0, 0.0); // Figura roja
    float a = 100, b = 50;
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float radio = a * cos(t) + b;
            float x = radio * cos(t);
            float y = radio * sin(t);
            glVertex2f(-x, y);
        }
    glEnd();
}

void dibujarRosaPolar() {
    glColor3f(1.0, 0.0, 0.0); // Figura roja
    float a = 100, b = 0;
    glBegin(GL_LINE_STRIP);
        for (float t = 0; t <= 2 * M_PI; t += 0.01) {
            float radio = a * cos(5*t) + b;
            float x = radio * cos(t);
            float y = radio * sin(t);
            glVertex2f(-x, y);
        }
    glEnd();
}
