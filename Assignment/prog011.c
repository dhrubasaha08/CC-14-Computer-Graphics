/******************************************************************************************************************
Name: Dhruba Saha
Program: Write a program in C to implement end point code generation algorithm.
Program No. 011
Date: 2023-04-29
*******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

char title[] = "End Point Code Generation Algorithm";
int winWidth = 1000;
int winHeight = 1000;
int range_x1 = -500;
int range_x2 = 500;
int range_y1 = -500;
int range_y2 = 500;

typedef struct point
{
    float x, y;
} point;

point a, b;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, winWidth, 0, winHeight);
}

void drawAxes(void)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(range_x1, 0.0);
    glVertex2f(range_x2, 0.0);
    glVertex2f(0.0, range_y1);
    glVertex2f(0.0, range_y2);
    glEnd();

    int num_ticks_x = (int)(range_x2 - range_x1);
    GLfloat tick_size_x = 0.1;
    GLfloat tick_spacing_x = (range_x2 - range_x1) / num_ticks_x;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i <= num_ticks_x; i++)
    {
        glVertex2f(range_x1 + i * tick_spacing_x, -tick_size_x);
        glVertex2f(range_x1 + i * tick_spacing_x, tick_size_x);
    }
    glEnd();

    int num_ticks_y = (int)(range_y2 - range_y1);
    GLfloat tick_size_y = 0.1;
    GLfloat tick_spacing_y = (range_y2 - range_y1) / num_ticks_y;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i <= num_ticks_y; i++)
    {
        glVertex2f(-tick_size_y, range_y1 + i * tick_spacing_y);
        glVertex2f(tick_size_y, range_y1 + i * tick_spacing_y);
    }
    glEnd();
}

void drawLine(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy, err;

    if (x0 < x1)
    {
        sx = 1;
    }
    else
    {
        sx = -1;
    }

    if (y0 < y1)
    {
        sy = 1;
    }
    else
    {
        sy = -1;
    }

    err = dx - dy;

    while (1)
    {
        glVertex2i(x0, y0);

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    drawLine(a.x, a.y, b.x, b.y);
    glEnd();

    glFlush();
}

void reshape(int width, int height)
{
    float aspect_ratio = (range_x2 - range_x1) / (range_y2 - range_y1);

    float cx = (range_x1 + range_x2) / 2.0;
    float cy = (range_y1 + range_y2) / 2.0;

    int size = width < height ? width : height;
    int x = (width - size) / 2;
    int y = (height - size) / 2;
    glViewport(x, y, size, size);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (aspect_ratio > 1)
    {
        float left = (range_x1 - cx) * aspect_ratio;
        float right = (range_x2 - cx) * aspect_ratio;
        glOrtho(left, right, range_y1 - cy, range_y2 - cy, -1.0, 1.0);
    }
    else
    {
        float bottom = (range_y1 - cy) / aspect_ratio;
        float top = (range_y2 - cy) / aspect_ratio;
        glOrtho(range_x1 - cx, range_x2 - cx, bottom, top, -1.0, 1.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    printf("Enter the first point (x, y): ");
    scanf("%f %f", &a.x, &a.y);
    printf("Enter the second point (x, y): ");
    scanf("%f %f", &b.x, &b.y);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow(title);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
