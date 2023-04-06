/************************************************************
Name: Dhruba Saha
Program: Implement two circle and highlight the intersection
Program No. Extra
Date: 2023-04-05
************************************************************/

#include <GL/glut.h>
#include <stdbool.h>
#include <math.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(5.0);

  // draw first circle
  float x1, y1, r1;
  x1 = -0.3; // x-coordinate of center of circle
  y1 = 0.0;  // y-coordinate of center of circle
  r1 = 0.3;  // radius of circle
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++)
  {
    float angle = i * M_PI / 180;
    glVertex2f(x1 + r1 * cos(angle), y1 + r1 * sin(angle));
  }
  glEnd();

  // draw second circle
  float x2, y2, r2;
  x2 = 0.2; // x-coordinate of center of circle
  y2 = 0.0; // y-coordinate of center of circle
  r2 = 0.3; // radius of circle
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++)
  {
    float angle = i * M_PI / 180;
    glVertex2f(x2 + r2 * cos(angle), y2 + r2 * sin(angle));
  }
  glEnd();

  // identify intersection points
  float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  float a = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2 * d);
  float h = sqrt(pow(r1, 2) - pow(a, 2));
  float x3 = x1 + a * (x2 - x1) / d;
  float y3 = y1 + a * (y2 - y1) / d;
  float x4 = x3 + h * (y2 - y1) / d;
  float y4 = y3 - h * (x2 - x1) / d;
  float x5 = x3 - h * (y2 - y1) / d;
  float y5 = y3 + h * (x2 - x1) / d;

  // draw intersection circle in red
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    float angle = i * M_PI / 180;
    float x = x4 + 0.05 * cos(angle);
    float y = y4 + 0.05 * sin(angle);
    if ((pow(x - x5, 2) + pow(y - y5, 2)) <= pow(0.05, 2))
    {
      glVertex2f(x, y);
    }
  }
  glEnd();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Two Circles");
  glutDisplayFunc(display);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glutMainLoop();
  return 0;
}
