#include<iostream>
#include<conio.h>
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<time.h>
/*
float xterrain[41]= {-2,-1.9,-1.8,-1.7,-1.6,-1.5,-1.4,-1.3,-1.2,-1.1,-1,-.9,-.8,-.7,-.6,-.5,-.4,-.3,-.2,-.1,0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2};
float yterrain[40];

static void assign_coord(float y[])
{
    y[0]=(rand()%100)/100-0.5;
    int sval;
    time_t t;//t is a time type variable
    sval=time(&t);
    srand(sval);
    for (int i=1; i<40; i++)
    {
        y[i]=y[i-1]+2*(-0.5+(rand()%2))*float((rand()%10))/100;
        while(y[i]-.5>0.75)
        {
            y[i]-=0.1;
        }
        while(y[i]-.5<-0.75)
        {
            y[i]+=0.1;
        }
    }
}

static void terrain_polygon(float x[],float y[])
{
    assign_coord(yterrain);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0.5,0);

    for(int i=0; i<=39; i++)
    {
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5);
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5);
        glEnd();
    }
    glutSwapBuffers();
    glFlush();
}

static void display()
{
    terrain_polygon(xterrain,yterrain);
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-ar, ar, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
*/

