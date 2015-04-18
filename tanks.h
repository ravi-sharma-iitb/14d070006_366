#ifndef TANKS_H_INCLUDED
#define TANKS_H_INCLUDED
#include"projectile.h"
#include"datatypes.h"
class tank
{
public:
    int position, angle;
    float rangle;
    tank(int pos)
    {
        position=pos;
        angle=45;
    }
    void tankDisplay()
    {
        glBegin(GL_POLYGON);
        glColor3d(0,0,1);
        rangle=1.0*angle/180*3.14;
        glVertex2d(xterrain[position]+0.04,yterrain[position]-0.44);
        glVertex2d(xterrain[position]+0.045,yterrain[position]-0.46);
        glVertex2d(xterrain[position]+0.03,yterrain[position]-0.5);
        glVertex2d(xterrain[position]-0.03,yterrain[position]-0.5);
        glVertex2d(xterrain[position]-0.045,yterrain[position]-0.46);
        glVertex2d(xterrain[position]-0.04,yterrain[position]-0.44);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3d(0,0,1);
        glVertex2d(xterrain[position]+0.025,yterrain[position]-0.44);
        glVertex2d(xterrain[position]+0.022,yterrain[position]-0.41);
        glVertex2d(xterrain[position]-0.022,yterrain[position]-0.41);
        glVertex2d(xterrain[position]-0.025,yterrain[position]-0.44);
        glEnd();
        glColor3d(0,0,0);
        //glutSwapBuffers();
        //glFlush();
        glBegin(GL_POLYGON);
         glVertex2d(xterrain[position]+0.04,yterrain[position]-0.442);
         glVertex2d(xterrain[position]-0.04,yterrain[position]-0.442);
         glVertex2d(xterrain[position]-0.04,yterrain[position]-0.44);
         glVertex2d(xterrain[position]+0.04,yterrain[position]-0.44);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2d(xterrain[position]+0.03,yterrain[position]-0.47);
         glVertex2d(xterrain[position]+0.03,yterrain[position]-0.5);
        glVertex2d(xterrain[position]-0.03,yterrain[position]-0.5);
        glVertex2d(xterrain[position]-0.03,yterrain[position]-0.47);
        glEnd();
        glColor3d(1,1,1);
        glBegin(GL_LINES);//nozzle
        glVertex2f(xterrain[position],yterrain[position]-0.4);
        glVertex2f(xterrain[position]+0.05*cos(rangle),yterrain[position]+0.1*sin(rangle)-0.4);
        glEnd();
        glutSwapBuffers();
        glFlush();
    }
};


#endif // TANKS_H_INCLUDED
