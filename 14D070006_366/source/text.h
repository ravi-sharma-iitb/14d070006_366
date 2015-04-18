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
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include"a.h"
#include <stdlib.h>
#include<time.h>
//#include"fin.h"
//#include"projectile.h"



void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
char defaultMessage[] = "GLUT means OpenGL.";
char *message = defaultMessage;

void
selectFont(int newfont)
{
  font = fonts[newfont];
  glutPostRedisplay();
}

void
selectMessage(int msg)
{
  switch (msg) {
  case 1:
    message = "abcdefghijklmnop";
    break;
  case 2:
    message = "ABCDEFGHIJKLMNOP";
    break;
  }
}

void
selectColor(int color)
{
  switch (color) {
  case 1:
    glColor3f(0.0, 1.0, 0.0);
    break;
  case 2:
    glColor3f(1.0, 0.0, 0.0);
    break;
  case 3:
    glColor3f(1.0, 1.0, 1.0);
    break;
  }
  glutPostRedisplay();
}

void
tick(void)
{
  glutPostRedisplay();
}

void
output(int x, int y, char *string)
{
  int len, i;

  glRasterPos2f(607.5+x,641.25+ y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  output(0, 24, "FIRE");
  output(100, 100, message);
  output(50, 145, "(positioned in pixels with upper-left origin)");
  glutSwapBuffers();
}

void
reshape(int w, int h)
{
  glViewport(1, 1, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  glMatrixMode(GL_MODELVIEW);
}

int
text(int argc, char **argv)
{
  int i, msg_submenu, color_submenu;

  glutInit(&argc, argv);
  for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-mono")) {
      font = GLUT_BITMAP_9_BY_15;
    }
  }
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(1350, 675);
  glutCreateWindow("GLUT bitmap font example");
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(tick);
  msg_submenu = glutCreateMenu(selectMessage);
  glutAddMenuEntry("abc", 1);
  glutAddMenuEntry("ABC", 2);
  color_submenu = glutCreateMenu(selectColor);
  glutAddMenuEntry("Green", 1);
  glutAddMenuEntry("Red", 2);
  glutAddMenuEntry("White", 3);
  glutCreateMenu(selectFont);
  glutAddMenuEntry("9 by 15", 0);
  glutAddMenuEntry("Times Roman 10", 1);
  glutAddMenuEntry("Times Roman 24", 2);
  glutAddSubMenu("Messages", msg_submenu);
  glutAddSubMenu("Color", color_submenu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
