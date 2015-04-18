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
int score11,score22;
tank t_left1(4), t_right1(17);

float x_proj=0;
int k=0,k2=0; //for projectile conditions-Ravi.
bool fire1=false;//turns true on mouse click
bool fire2=true;// turns true on projectile completion
bool isFirst=1;
float mouse_x[1]= {0}, mouse_y[1]= {0};//Start point of projectile
float end_x, end_y;

 //true for player on left

//void *font = GLUT_BITMAP_TIMES_ROMAN_24;
/*void *fonts[] =
{
    GLUT_BITMAP_9_BY_15,
    //GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24
};*/

/*void
selectFont(int newfont)
{
    font = fonts[newfont];
    glutPostRedisplay();
}*/


//void *font = GLUT_BITMAP_TIMES_ROMAN_24;

/*void output(float x, float y, char *string)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}*/

void terrainDistort(float x, float y)
{
    int lowx=10*(x+1);
    yterrain[lowx]-=(yterrain[lowx]>-1)?0.05:0;
    yterrain[lowx+1]-=(yterrain[lowx+1]>-1)?0.05:0;
    /*glColor3f(1,0.6,0);
    glBegin(GL_POLYGON);
    f
or(int i=0; i<1000; ++i)
    {
        glVertex3f(x+cos(2*3.14159*i/1000.0)/20,y+sin(2*3.14159*i/1000.0)/10,0);
    }
    glEnd();
    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();*/

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
            //std::cin>>power;
            power=0;
            if(power<0|| power>100)
                std::cout<<"Please enter power between 0 and 100"<<std::endl;
        }
        while(power<0 || power>100);

        std::cout<<"enter the angle"<<std::endl;
        //std::cin>>angle;
        //power=power/50;
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
  // std::cout<<"score a "<<scoreA<<endl;
  //   std::cout<<"sending score A "<<scoreA<<std::endl;
}
void score_print4()
{
   // std::cout<<"sending score B "<<scoreB<<std::endl;
    output2(0.88, 0.7, scoreB);
}

void projectileFunc()
{
    if(isFirst)
    {
        //getValues();
        isFirst=0;
    }
    int lowx=10*((x_proj+mouse_x[0])+1);
    float t=x_proj+mouse_x[0];
    float ymin=yterrain[lowx]+(t-xterrain[lowx])*(yterrain[lowx+1]-yterrain[lowx])/0.1-0.5;

    // std::cout<<fire2<<"  a ";
    //std::cout<<fire<<std::endl; //equation
    if(fire1 && mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))>ymin) //equation
    {

        //std::cout<<(mouse_y[0]+2.0*((t)*tan(rangle)-(t)*(t)/(power*power*cos(rangle)*cos(rangle)))>ymin)<<" ";
        x_proj+=0.0035*cos(rangle);
        k++;
        k2++;
        glColor3d(0.5,0,0.50);
        //for(float i=0; i<=1; i+=0.1)
        glBegin(GL_POINTS);
        glVertex2f(t,mouse_y[0]+2.0*((x_proj)*tan(rangle)-(x_proj)*(x_proj)/(power*power*cos(rangle)*cos(rangle)))); //equation
        //glVertex2f(i+0.1,i+0.1-(i+0.1)*(i+0.1));
        glEnd();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay();

    }

    // std::cout<<(mouse_y[0]+2.0*((t)*tan(rangle)-(t)*(t)/(power*power*cos(rangle)*cos(rangle)))>ymin)<<" ";
    // std::cout<<k<<" ";

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
    //bool fire3=!(mouse_y[0]+2.0*((t)*tan(rangle)-(t)*(t)/(power*power*cos(rangle)*cos(rangle)))>ymin);//end of projectile
    if(k2>0 &&k==0)
    {
        end_x=x_proj+mouse_x[0];
        end_y=ymin;
        k2=0;
        //std::cout<<end_x<<" , "<<end_y<<std::endl;
        //std::cout<<"score is "<<score(end_x,end_y)<<std::endl;
        if (!player)
        {
            score1+=score(end_x,end_y);
            //std::cout<<"score is "<<score1<<std::endl;
            score11=(int)score1;
            //score_print1(score11);
            stringstream str1;
            str1<<score11;
            string temp_str1=str1.str();
            scoreA=(char*)temp_str1.c_str();
            std::cout<<"score of A is "<<scoreA<<std::endl;

        }

        else
        {
            score2+=score(end_x,end_y);

            score22=(int)score2;
            //score_print2(score22);
             stringstream str2;
            str2<<score22;
            string temp_str2=str2.str();
            scoreB=(char*)temp_str2.c_str();
            std::cout<<"score of B is "<<scoreB<<std::endl;


        }
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        terrainDistort(end_x,end_y);
        gameTurnNo--;
        //mouse_x[0]= 0;
         //mouse_y[0]= 0;
         power=0;
         angle=90;
         fire1=false;
         //x_proj=0;
        //InitTerrain=1

        //terrainDistort(end_x,end_y);
        glutPostRedisplay();
        //getValues();

    }
}

    //std::cout<<end_x<<end_y;


#endif // PROJECTILE_H_INCLUDED
