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

using namespace std;

// global variables
bool GameStart=0;
float xterrain[21]= {-1,-.9,-.8,-.7,-.6,-.5,-.4,-.3,-.2,-.1,0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1};
float yterrain[21];
int i,i1;



bool InitTerrain=1;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
    GLUT_BITMAP_9_BY_15,
    //GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24
};

void selectFont(int newfont) // method to select the fonts
{
    font = fonts[newfont];
    glutPostRedisplay();
}


void output(float x, float y, char *string) // method to display things on screen
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

static void assign_coord(float y[]) // assign the coordinates on screen
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

static void terrain_polygon(float x[],float y[]) // method to make the random  terrain
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
    output(-.62,-.968,"POWER");
    output(0.38,-.968,"ANGLE");


    glutSwapBuffers();
    glFlush();
    if(InitTerrain)
    {
        InitTerrain=0;
    }
}


void HomeScreen() // method to display the home screen
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
    glColor3f(1,1,1);
    output(-0.055,-0.117,"INSTRUCTIONS:");
    output(-0.055,-0.217,"W/S:-angle increase/decrease(0-180)");
    output(-0.055,-0.317,"J/L:-tank movement(j=left,l=right)");
    output(-0.055,-0.417,"D/A:-power increase/decrease(0-100)");
    glutSwapBuffers();
    glFlush();
    glutPostRedisplay();
}
void GameOverScreen()
{glColor3f(1,1,1);
    output(-0.055,-0.017+0.1,"Game Over");/////////////////////////////////ravi

    glColor3f(1,1,1);
    output(-0.055,-0.1,"Click Anywhere to Exit");
    if (score11>score22)
        output(-.055,-0.017,"WINNER IS PLAYER 1");

        else if (score11<score22)
        output(-.055,-0.017,"WINNER IS PLAYER 2");

        else
            output(-.055,-0.017,"MATCH DRAW");

    glutSwapBuffers();
    glFlush();
    glutPostRedisplay();

}


#endif // FIN_H_INCLUDED
