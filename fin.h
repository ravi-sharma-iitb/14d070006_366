#ifndef FIN_H_INCLUDED
#define FIN_H_INCLUDED
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
#include<sstream>
#include<string>
#include"datatypes.h"
//#include"tanks.h"
using namespace std;

//tank t3;
bool GameStart=0;
float xterrain[21]= {-1,-.9,-.8,-.7,-.6,-.5,-.4,-.3,-.2,-.1,0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1};
float yterrain[21];
int i,i1;

//char *scoreA="0",*scoreB="0";

bool InitTerrain=1;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
    GLUT_BITMAP_9_BY_15,
    //GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24
};

void selectFont(int newfont)
{
    font = fonts[newfont];
    glutPostRedisplay();
}


void output(float x, float y, char *string)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}
void output2(float x, float y, char *string)
{
    int len, i;
    //std::cout<<"arbit "<<string;
   // selectFont(0);
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

void output1(float x, float y, char *string)
{
    int len, i;
    //std::cout<<"arbit2 "<<string;
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

void output4(float x, float y, char *string)
{
    int len, i;
    selectFont(0);
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

void output5(float x, float y, char *string)
{
    int len, i;
    selectFont(0);
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

static void assign_coord(float y[])
{
    y[0]=1.0*(rand()%100)/100-0.5;
    int sval;
    time_t t;//t is a time type variable
    sval=time(&t);
    srand(sval);
    for (int i=1; i<21; i++)
    {
        y[i]=y[i-1]+2*(-0.5+(rand()%2))*float((rand()%10))/50;
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
        for(int i=0; i<=19; i++)
    {
        if(InitTerrain)
        {
            glutSwapBuffers();
            glFlush();
        }
        glColor3d(0,.5,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5);
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5);
        glEnd();
        glColor3d(0,0.4,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5-0.1*(y[i]+1));
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5-0.1*(y[i+1]+1));
        glEnd();
        glColor3d(0,0.32,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5-0.2*(y[i]+1));
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5-0.2*(y[i+1]+1));
        glEnd();
        glColor3d(0,0.28,0);
        glBegin(GL_POLYGON);
        glVertex2f(x[i],y[i]-.5-0.3*(y[i]+1));
        glVertex2f(x[i],-1);
        glVertex2f(x[i+1],-1);
        glVertex2f(x[i+1],y[i+1]-0.5-0.3*(y[i+1]+1));
        glEnd();
        glBegin(GL_LINES);//power set
        glColor3f(1,1,1);
        glVertex2f(-0.7+0.4*power/2,-0.89);
        glVertex2f(-0.7+0.4*power/2,-0.9);
        glEnd();

        glBegin(GL_LINES);//angle set
        glColor3f(1,1,1);
        glVertex2f(0.3+0.4*angle/180,-0.89);
        glVertex2f(0.3+0.4*angle/180,-0.9);
        glEnd();

    for (int poly=0;poly<100;poly++)
    {
    glColor3f(0.01*poly,0,0);
    glBegin(GL_POLYGON); //power bar
    glVertex2f(0.3+(double)(poly)/250,-.9);
    glVertex2f(0.3+(double)(poly)/250,-1);
    glVertex2f(0.3+(double)(poly+1)/250,-1);
    glVertex2f(0.3+(double)(poly+1)/250,-.9);
    glEnd();
    }

    for (int poly=0;poly<100;poly++)
    {
    glColor3f(0.01*poly,0,0);
    glBegin(GL_POLYGON); //power bar
    glVertex2f(-0.7+(double)(poly)/250,-.9);
    glVertex2f(-0.7+(double)(poly)/250,-1);
    glVertex2f(-0.7+(double)(poly+1)/250,-1);
    glVertex2f(-0.7+(double)(poly+1)/250,-.9);
    glEnd();
    }

        glEnd();
    }

    if(InitTerrain)
    {
        glutSwapBuffers();
        glFlush();
    }
    glColor3d(0.5,0.5,0.5);// fire button
    glBegin(GL_POLYGON);
    glVertex2f(-0.1,-.9);
    glVertex2f(-0.1,-1);
    glVertex2f(0.1,-1);
    glVertex2f(0.1,-.9);
    glEnd();


    glColor3d(1,0,0);
    output(-.045, -.97, "FIRE");
    glColor3d(1,1,1);
    output(-.9, .8, "PLAYER 1");
    output(.8, .8, "PLAYER 2");

  // std::cout<<"score b "<<scoreB<<endl;
    glutSwapBuffers();
    glFlush();
    if(InitTerrain)
    {
        InitTerrain=0;
    }
}
/*
void score_print3()
{
    output(-.88, 0.7, scoreA);
  // std::cout<<"score a "<<scoreA<<endl;

}
void score_print4()
{
    output(0.88, 0.7, scoreB);
}



static void score_print1(int score11)
{
            stringstream str1;
            str1<<score11;
            string temp_str1=str1.str();
            scoreA=(char*)temp_str1.c_str();
            std::cout<<"score of A is "<<scoreA<<std::endl;

          // output4(-.88, 0.7, scoreA);
}

static void score_print2(int score22)
{

            stringstream str2;
            str2<<score22;
            string temp_str2=str2.str();
            scoreB=(char*)temp_str2.c_str();
            std::cout<<"score of B is "<<scoreB<<std::endl;

          // output5(0.88, 0.7, scoreB);
}
*/

/*
static void resize(int width, int height)  //look for it
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-ar, ar, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}*/

void HomeScreen()
{
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.067,-.055);
    glVertex2f(-0.067,.055);
    glVertex2f(0.067,.055);
    glVertex2f(0.067,-.055);
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.06,-.05);
    glVertex2f(-0.06,.05);
    glVertex2f(0.06,.05);
    glVertex2f(0.06,-.05);
    glEnd();
    glColor3f(0,0,0);
    output(-0.055,-0.017,"START");/////////////////////////////////ravi
    glutSwapBuffers();
    glFlush();
    glutPostRedisplay();
}
void GameOverScreen()
{glColor3f(1,1,1);
    output(-0.055,-0.017+0.1,"Game Over");/////////////////////////////////ravi

    glColor3f(1,1,1);
    output(-0.055,-0.017,"Click Anywhere to Exit");
    glutSwapBuffers();
    glFlush();
    glutPostRedisplay();

}


#endif // FIN_H_INCLUDED
