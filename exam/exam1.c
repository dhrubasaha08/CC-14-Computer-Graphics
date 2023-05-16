/*****************************************************************************************************
Name: Dhruba Saha
Program: Write a C program to draw a ellipse and a circle whose radius is the length of the minor axis.
******************************************************************************************************/

#include <GL/glut.h>
#include <math.h>

GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat major = 1.0;
GLfloat minor = 0.5;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
}

void drawAxes() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);

    glVertex2f(-2.0, 0.0);
    glVertex2f(2.0, 0.0);

    glVertex2f(0.0, -2.0);
    glVertex2f(0.0, 2.0);

    glEnd();
}

void drawEllipse(GLfloat x, GLfloat y, GLfloat a, GLfloat b) {
    glBegin(GL_LINE_LOOP);
    for (GLint i = 0; i < 360; i++) {
        GLfloat theta = i * 3.14159 / 180.0;
        GLfloat xi = x + a * cos(theta);
        GLfloat yi = y + b * sin(theta);
        glVertex2f(xi, yi);
    }
    glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    glBegin(GL_LINE_LOOP);
    for (GLint i = 0; i < 360; i++) {
        GLfloat theta = i * 3.14159 / 180.0;
        GLfloat xi = x + radius * cos(theta);
        GLfloat yi = y + radius * sin(theta);
        glVertex2f(xi, yi);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();



    glColor3f(1.0, 0.0, 0.0);
    drawEllipse(x, y, major, minor);

    glColor3f(0.0, 1.0, 0.0);
    drawCircle(x, y, minor);

    drawAxes();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Ellipse and Circle(Radius = Minor)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
