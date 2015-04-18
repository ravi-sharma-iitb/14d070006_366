
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
//#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<time.h>
#include"fin.h"
#include"projectile.h"
#include"tanks.h"
//bool InitTerrain=1;
//tank t_left(4), t_right(17);

static void display()
{
    if(!GameStart)
    {
        HomeScreen();
    }
    else if(gameTurnNo!=0)
    {
        if (InitTerrain)glClear(GL_COLOR_BUFFER_BIT);

        terrain_polygon(xterrain,yterrain);

        t_left1.tankDisplay();
        t_right1.tankDisplay();
        score_print3();
        score_print4();
       // red_bar();


       // glColor3d(1,1,1);

        // output4(-.88, 0.7, scoreA);
       // glColor3d(1,1,1);
        // output5(0.88, 0.7, scoreB);
        projectileFunc();
        //angle_bar();

    }
    else
    {

        GameOverScreen();

    }
}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {

    case GLUT_LEFT_BUTTON:
        if(fire2 && state==GLUT_DOWN  && x>607 && x<743 && y>641 && y<675 && gameTurnNo!=0 &&GameStart==1)
        {
            x_proj=0;
            fire1=true;
            mouse_x[0]=(player)? xterrain[t_left1.position]:xterrain[t_right1.position];
            mouse_y[0]=(player)? yterrain[t_left1.position]-0.47:yterrain[t_right1.position]-0.47;
            player=!player;
            glutPostRedisplay();
        }
        else if (state==GLUT_DOWN  && x>-34+675 && x<34+675 && y<1.04*(675/2) && y>0.96*(675/2))
        {
            GameStart=1;
            //glClear(GL_COLOR_BUFFER_BIT);
        }
        else if (state==GLUT_DOWN  && gameTurnNo<=0)
        {
            exit(0);
            //glClear(GL_COLOR_BUFFER_BIT);
        }
    default:
        break;
    }
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    //case 27 :
    case 'd':

    {
        if (gameTurnNo!=0 &&GameStart==1){
        power+=.02;
        std::cout<<"power is "<<power*50;
        if (power>=2)
        {
            power=0;

        }
    }}
    break;
    case 'a':

    {if (gameTurnNo!=0 &&GameStart==1){
        power-=0.02;
        std::cout<<"power is "<<power*50;
        if (power<=0)
            power=2;
    }}
    break;
    case 'w':
    {if (gameTurnNo!=0 &&GameStart==1){
        angle+=1;
        rangle=1.0*angle/180*3.14;
        if (angle>=180)
            angle=0;
        std::cout<<"angle is "<<angle;
    }}
    break;
    case 's':
    {if (gameTurnNo!=0 &&GameStart==1){
        angle-=1;
        rangle=1.0*angle/180*3.14;
        if (angle<=0)
            angle=180;
        std::cout<<"angle is "<<angle;
    }}
    break;
     case 'j':

    {if (gameTurnNo!=0 &&GameStart==1){
        glClear(GL_COLOR_BUFFER_BIT);
        if(player) t_left1.position-=(t_left1.position>0)?1:0;
        if(!player) t_right1.position-=(t_right1.position>11)?1:0;
    }}
    break;
    case 'l':

    {if (gameTurnNo!=0 &&GameStart==1){
        glClear(GL_COLOR_BUFFER_BIT);
        if(player) t_left1.position+=(t_left1.position<10)?1:0;
        if(!player) t_right1.position+=(t_right1.position<20)?1:0;
    }}
    break;
    }
}


static void idle(void)
{
    glutPostRedisplay();
}
int main(int argc, char *argv[])
{

    //getValues();
    assign_coord(yterrain);
    // std::cin>>mouse_x[0]>>mouse_y[0];
    glutInit(&argc, argv);
    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-mono"))
        {
            font = GLUT_BITMAP_9_BY_15;
        }
    }
    glutInitWindowSize(1350,675);
    glutInitWindowPosition(0,0);
    glutCreateWindow("POCKET TANKS");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //glutReshapeFunc(resize);
    glClearColor(0,0,0,1);
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMainLoop();
    getch();
}
