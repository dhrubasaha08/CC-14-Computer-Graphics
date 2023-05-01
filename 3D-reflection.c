#include <GL/glut.h>
#define CUBE_SIZE 2.0
GLfloat cubePosition[3] = {0.0, 0.0, 0.0};
GLfloat cubeRotationAngle = 90.0;
GLfloat lightPosition[4] = {5.0, 5.0, 5.0, 1.0};
GLfloat cubeColor[4] = {1.0, 0.0, 0.0, 1.0};
GLfloat reflectionColor[4] = {0.0, 0.0, 1.0, 1.0};
GLfloat floorPlane[4] = {0.0, 1.0, 0.0, 0.0};
GLfloat floorSize = 10.0;
GLfloat floorColor[4] = {0.5, 0.5, 0.5, 1.0};

void drawCube()
{
   glPushMatrix();
   glTranslatef(cubePosition[0], cubePosition[1], cubePosition[2]);
   glRotatef(cubeRotationAngle, 1.0, 1.0, 1.0);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, cubeColor);
   glutSolidCube(CUBE_SIZE);
   glPopMatrix();
}

void drawFloor()
{
   glPushMatrix();
   glTranslatef(0.0, -CUBE_SIZE / 2.0, 0.0);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, floorColor);
   glBegin(GL_QUADS);
   glNormal3f(floorPlane[0], floorPlane[1], floorPlane[2]);
   glVertex3f(-floorSize, 0.0, -floorSize);
   glVertex3f(-floorSize, 0.0, floorSize);
   glVertex3f(floorSize, 0.0, floorSize);
   glVertex3f(floorSize, 0.0, -floorSize);
   glEnd();
   glPopMatrix();
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
   drawCube();
   glPushMatrix();
   glScalef(1.0, -1.0, 1.0); // Reflect the scene
   glTranslatef(cubePosition[0], -cubePosition[1], cubePosition[2]);
   glRotatef(cubeRotationAngle, 1.0, -1.0, 1.0);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, reflectionColor);
   glutSolidCube(CUBE_SIZE);
   glPopMatrix();
   drawFloor();
   glutSwapBuffers();
}

void reshape(int width, int height)
{
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 'q':
         exit(0);
         break;
      case 'r':
         cubeRotationAngle += 90.0;
         glutPostRedisplay();
         break;
      case 'R':
         cubeRotationAngle -= 90.0;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

void special(int key, int x, int y)
{
   switch (key)
   {
      case GLUT_KEY_LEFT:
         cubePosition[0] -= 0.5;
         glutPostRedisplay();
         break;
      case GLUT_KEY_RIGHT:
         cubePosition[0] += 0.5;
         glutPostRedisplay();
         break;
      case GLUT_KEY_UP:
         cubePosition[2] -= 0.5;
         glutPostRedisplay();
         break;
      case GLUT_KEY_DOWN:
         cubePosition[2] += 0.5;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("3D Reflection");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutMainLoop();
   return 0;
}