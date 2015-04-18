#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include"fin.h"
#include<math.h>
#include"tanks.h"
#include <ctype.h>
#include"datatypes.h"

using namespace std;

float score1=0,score2=0;
char *scoreA="0",*scoreB="0";

tank t_left1(4), t_right1(17);

float x_proj=0;
int k=0,k2=0; //for projectile conditions-Ravi.
bool fire1=false;//turns true on mouse click
bool fire2=true;// turns true on projectile completion
bool isFirst=1;
float mouse_x[1]= {0}, mouse_y[1]= {0};//Start point of projectile
float end_x, end_y;

//true for player on left



void terrainDistort(float x, float y)
{
    int lowx=10*(x+1);
    yterrain[lowx]-=(yterrain[lowx]>-1)?0.05:0;
    yterrain[lowx+1]-=(yterrain[lowx+1]>-1)?0.05:0;
}

float score(float xprojfin,float yprojfin)
{
    float dist;
    if (player==0)
    {
        dist=pow((((xterrain[t_right1.position]-xprojfin)*(xterrain[t_right1.position]-xprojfin))+((yterrain[t_right1.position]-0.47-yprojfin)*(yterrain[t_right1.position]-0.47-yprojfin))),0.5);
        std::cout<<xterrain[t_right1.position]<<"   "<<yterrain[t_right1.position]<<std::endl;
    }
    else
    {
        dist=pow((((xterrain[t_left1.position]-xprojfin)*(xterrain[t_left1.position]-xprojfin))+((yterrain[t_left1.position]-0.47-yprojfin)*(yterrain[t_left1.position]-0.47-yprojfin))),0.5);
        std::cout<<xterrain[t_left1.position]<<"   "<<yterrain[t_left1.position]<<std::endl;
    }
    std::cout<<dist<<std::endl;
    if ((0.3-dist)>0)
        return ((0.3-dist)/0.3)*100;

    else
        return 0;
}


void getValues()
{

    try
    {
        do
        {
            std::cout<<"enter the power:"<<std::endl;


            power=0;
            if(power<0|| power>100)
                std::cout<<"Please enter power between 0 and 100"<<std::endl;
        }
        while(power<0 || power>100);

        std::cout<<"enter the angle"<<std::endl;


        angle=90;
        rangle=1.0*angle/180*3.14;
    }
    catch(...)
    {
        std::cout<<"Please enter a valid power"<<std::endl;
    }
}

void score_print3()
{

    output1(-.88, 0.7, scoreA);

}

void score_print4()
{

    output2(0.88, 0.7, scoreB);
}

void projectileFunc()
{
    if(isFirst)
    {

        isFirst=0;
    }
    int lowx=10*((x_proj+mouse_x[0])+1);
    float t=x_proj+mouse_x[0];
    float ymin=yterrain[lowx]+(t-xterrain[lowx])*(yterrain[lowx+1]-yterrain[lowx])/0.1-0.5;


    if(fire1 && mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin) //equation
    {


        x_proj+=0.0035*cos(rangle);
        k++;
        k2++;
        glColor3d(0.5,0,0.50);

        glBegin(GL_POINTS);
        glVertex2f(t,mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))); //equation

        glEnd();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay();

    }


    if (k!=0)
    {

        if ( mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin)//equation
            fire2=false;


        else if( mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin==0)//equation
        {

            fire2=true;
            k=0;

        }
    }

    if(k2>0 &&k==0)
    {
        end_x=x_proj+mouse_x[0];
        end_y=ymin;
        k2=0;

        if (!player)
        {
            score1+=score(end_x,end_y);

            score11=(int)score1;

            stringstream str1;
            str1<<score11;
            string temp_str1=str1.str();
            scoreA=(char*)temp_str1.c_str();
            std::cout<<"score of A is "<<scoreA<<std::endl;

        }

        else if (player)
        {
            score2+=score(end_x,end_y);

            score22=(int)score2;

            stringstream str2;
            str2<<score22;
            string temp_str2=str2.str();
            scoreB=(char*)temp_str2.c_str();
            std::cout<<"score of B is "<<scoreB<<std::endl;

        }
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        if (!player) score_print3();
        else if (player) score_print4();

        terrainDistort(end_x,end_y);
        gameTurnNo--;

        power=0;
        angle=90;
        fire1=false;

        glutPostRedisplay();


    }
}




#endif // PROJECTILE_H_INCLUDED
