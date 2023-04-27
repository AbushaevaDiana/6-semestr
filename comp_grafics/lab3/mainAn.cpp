#include <GL/glut.h>
#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define DEG2RAD M_PI/180.0

using namespace std;

const float colors[10][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 0},
    {1, 0, 1},
    {0, 1, 1},
    {0.5, 0.3, 0.2},
    {0.2, 0.6, 0.8},
    {0.3, 0.9, 0.1},
    {1.0, 0.5, 0.2}
};

float speed= 0.0f;
int fishFlag = 1;

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_PROJECTION);
    glDepthFunc(GL_LEQUAL);
    gluOrtho2D(-800.0, 800.0, -600.0, 600.0);
}

void DrawEllipse(float x, float y, float radiusX, float radiusY)
{
    int i;
    float rad ;
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++)
    {
        glVertex2f(x + cos(i * DEG2RAD) * radiusX, y + sin(i * DEG2RAD) * radiusY);
    }
    glEnd();
}

//Water
void DrawWater()
{
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.9);
    glVertex3f(-800.0, -600.0, 0);
    glVertex3f(800.0, -600.0, 0);
    glVertex3f(800.0, 600.0, 0.0);
    glColor3f(0.3,0.9,0.8);
    glVertex3f(-800.0, 600.0, 0);
    glEnd();
}

//Stone 1
void DrawStone1(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.1,0.003);
    glVertex3f(x-30, 0.0, 0);
    glColor3f(0.7,0.4,0.05);
    glVertex3f(x-15, y/2, 0);
    glVertex3f(x-5, y/3, 0.0);
    glVertex3f(x+5, y/3, 0);
    glColor3f(x+15, y/2, 0);
    glVertex3f(x+30, 0.0, 0);
    glEnd();

    glPopMatrix();
}

//Stone 2
void DrawStone2(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.1,0.003);
    DrawEllipse(x, y, 4*y, y*2);
    glEnd();

    glPopMatrix();
}

//Stone 3
void DrawStone3(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0);
    glVertex3f(x-30, 0.0, 0);
    glColor3f(0.7, 0.4, 0.05);
    glVertex3f(x-15, y/2, 0);
    glVertex3f(x-5, y/6, 0);
    glVertex3f(x+5, y/6, 0);
    glVertex3f(x+15, y/2, 0);
    glColor3f(0.3,0.1,0.003);
    glVertex3f(x+30, 0, 0);
    glEnd();

    glPopMatrix();
}

//Stone 4
void DrawStone4(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.5, 0);
	glVertex2f(x, y);
        for(int i = 0; i <= 6; i++) 
        { 
	    glVertex2f(
		       x + (y*2 * cos(i * 2*3.14 / 6)), 
		       y + (y*2 * sin(i * 2*3.14 / 6))
		      );
	}
    glEnd();

    glPopMatrix();
}

//Stone 5
void DrawStone5(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.25, 0.1);
	glVertex2f(x, y);
        for(int i = 0; i <= 32; i++) 
        { 
	    glVertex2f(
		       x + (y*2 * cos(i * 2*3.14 / 32)), 
		       y + (y*2 * sin(i * 2*3.14 / 32))
		      );
	}
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    float newX = x+y*2;
    glColor3f(1, 0.9, 0.8);
	glVertex2f(newX, y/2);
        for(int i = 0; i <= 12; i++) 
        { 
	    glVertex2f(
		       newX + (y * cos(i * 2*3.14 / 12)), 
		       y + (y * sin(i * 2*3.14 / 12))
		      );
	}
    glEnd();

    glPopMatrix();
}

//Plant
void DrawPlant(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

//проверить выпуклый ли полигон
    //Seaweed 1
    glBegin(GL_POLYGON);
    glColor3f(0.07,0.35,0.01);
    glVertex3f(x, 0.0, 0);
    glVertex3f(x+45, y/5, 0);
    glColor3f(0.6,0.4,0.01);
    glVertex3f(x+15, y/3, 0.0);
    glVertex3f(x+35, y/2, 0.0);
    glColor3f(0.4, 0.6, 0.01);
    glVertex3f(x, y, 0);
    glVertex3f(x-35, y/2, 0.0);
    glVertex3f(x-15, y/3, 0);
    glVertex3f(x-45, y/5, 0);
    glColor3f(0.07,0.35,0.01);
    glVertex3f(x, 0.0, 0);
    glEnd();

    glPopMatrix();
}

//Fish1
void DrawFish1(float x, float y, int color, float rx, float ry)
{
    glLoadIdentity();
    glPushMatrix();

    if(fishFlag == 1)
    {
        glTranslatef(-1*speed, 0.0f, 0.0f);
    }
    else
    {
        glTranslatef(speed, 0.0f, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
    }
    speed += 0.1f;

    //Tail
    glBegin(GL_POLYGON);
    glColor3f(color*0.1, color*0.2, color*0.3);
    glVertex3f(x+rx, y, 0.0);
    glColor3f(color*0.01, color*0.02, color*0.03);
    glVertex3f(x+rx+50.0, y+50.0, 0.0);
    glColor3f(color*0.001, color*0.002, color*0.003);
    glVertex3f(x+rx+100.0, y+20.0, 0.0);
    glVertex3f(x+rx+70.0, y, 0.0);
    glVertex3f(x+rx+100, y-20.0, 0.0);
    glColor3f(color*0.01, color*0.02, color*0.03);
    glVertex3f(x+rx+50.0, y-50.0, 0.0);
    glColor3f(color*0.1, color*0.2, color*0.3);
    glVertex3f(x+rx, y, 0.0);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3f(colors[color][0], colors[color][1], colors[color][2]);
    DrawEllipse(x, y, rx, ry);
    glEnd();

   //Eye
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    DrawEllipse(x-50.0, y+20.0, ry/2, ry/2);
    glColor3f(1.0, 1.0, 1.0);
    DrawEllipse(x-40.0, y+30.0, ry/8, ry/8);
    glEnd();

    glPopMatrix();
}

//Fish2
void DrawFish2(float x, float y, int color, float rx, float ry)
{
    glLoadIdentity();
    glPushMatrix();

    if(fishFlag == 1)
    {
        glTranslatef(-1*speed*0.5, 0.0f, 0.0f);
    }
    else
    {
        glTranslatef(speed*0.5, 0.0f, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
    }
    speed += 0.1f;

    //Body
    glBegin(GL_POLYGON);
    glColor3f(colors[color][0], colors[color][1], colors[color][2]);
    DrawEllipse(x, y, rx, ry);
    glEnd();

    //Tail
    glBegin(GL_POLYGON);
    glColor3f(colors[color][0], colors[color][1], colors[color][2]);
    DrawEllipse(x+rx-10, y+15, ry, ry);
    DrawEllipse(x+rx-10, y-15, ry, ry);
    DrawEllipse(x+rx+10, y, ry, ry);
    glEnd();

   //Eye
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    DrawEllipse(x-50.0f, y+20.0f, ry/2, ry/2);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawEllipse(x-40.0f, y+30.0f, ry/8, ry/8);
    glEnd();

    glPopMatrix();
}

//Fish3
void DrawFish3(float x, float y, int color)
{
    glLoadIdentity();
    glPushMatrix();

    if(fishFlag == 1)
    {
        glTranslatef(-1*speed*2, 0.0f, 0.0f);
    }
    else
    {
        glTranslatef(speed*2, 0.0f, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
    }
    speed += 0.1f;

    //Tail
    glBegin(GL_POLYGON);
    glColor3f(color*0.1f, color*0.2f, color*0.3f);
    glVertex3f(x+50.0f, y, 0.0f);
    glColor3f(color*0.01f, color*0.02f, color*0.03f);
    glVertex3f(x+110.0f, y+50.0f, 0.0f);
    glColor3f(color*0.001, color*0.002, color*0.003f);
    glVertex3f(x+160.0f, y+20.0f, 0.0f);
    glVertex3f(x+130.0f, y, 0.0f);
    glVertex3f(x+160.0f, y-20.0f, 0.0f);
    glColor3f(color*0.01f, color*0.02f, color*0.03f);
    glVertex3f(x+110.0f, y-50.0f, 0.0f);
    glColor3f(color*0.1f, color*0.2f, color*0.3f);
    glVertex3f(x+50.0f, y, 0.0f);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
        glVertex3f(x-80.0f, y, 0.0f);
        glVertex3f(x+80.0f, y+150.0f, 0.0f);
        glVertex3f(x+80.0f, y-150.0f, 0.0f);
        glVertex3f(x-80.0f, y, 0.0f);
    glEnd();

   //Eye
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    DrawEllipse(x-50.0f, y+20.0f, 20.0f, 20.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawEllipse(x-40.0f, y+30.0f, 5.0f, 5.0f);
    glEnd();


    glPopMatrix();
}

void DrawBubble(float x, float y, float r, float speedBub)
{
    glLoadIdentity();
    glPushMatrix();
    if(fishFlag == 1)
    {
        glTranslatef(0.0f, speedBub*speed, 0.0f);
    }
    else
    {
        glTranslatef(0.0f, speedBub*speed, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
    }

    glBegin(GL_POLYGON);
      glColor3f(0.95, 1.0, 1.0);
      DrawEllipse(x, y, r, r);
    glEnd();

    glPopMatrix();
   
}

void Update()
{
    if(speed>200.0f && fishFlag!=0)
    {
        speed-=200.0f;
        fishFlag = 0;
    }
    else if(speed>200.0f && fishFlag==0)
    {
        speed-=200.0f;
        fishFlag = 1;
    }
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    DrawWater();

    DrawStone2(1400.0f, 20.0f);
    DrawStone4(240.0f, 25.0f);
    DrawStone2(100.0f, 10.0f);
    DrawStone2(800.0f, 20.0f);
    DrawStone1(60.0f, 110.0f);
    DrawStone3(550.0f, 110.0f);
    DrawStone4(900.0f, 20.0f);

    DrawFish2(570.0f, -400.0f, 4, 120.0f, 80.0f);

    DrawPlant(600.0f, 130.0f);
    DrawPlant(300.0f, 120.0f);
    DrawPlant(0.0f, 200.0f);
    DrawPlant(1200.0f, 200.0f);
    DrawPlant(1500.0f, 80.0f);
    DrawPlant(1200.0f, 240.0f);

    DrawStone1(700.0f, 90.0f);
    DrawStone5(1040.0f, 20.0f);
    DrawStone5(430.0f, 20.0f);

    DrawBubble(200.0, 400.0, 10.0, 6);
    DrawBubble(-550.0, -100.0, 17.0, 8);
    DrawBubble(-550.0, -100.0, 7.0, 3);
    
    DrawFish1(350.0f, 400.0f, 5, 150.0f, 40.0f);
    DrawFish1(-600.0f, 300.0f, 7, 150.0f, 40.0f);
    DrawFish2(-270.0f, 500.0f, 9, 120.0f, 80.0f);
    DrawFish3(-400.0f, -100.0f, 1);

    DrawBubble(-600.0, -500.0, 10.0, 6);
    DrawBubble(600.0, -500.0, 17.0, 8);

    glFlush();
    Update();
    glutSwapBuffers();
}

void ChangeSize(int w, int h) {
    double ww = w*0.75, hh = h;
    if (w*0.75 > h)
       glOrtho(-2.0 * (ww/hh), 2.0 * (ww/hh), -2.0, 2.0, -1.0, 1.0);
    else
      glOrtho(-2.0, 2.0, -2.0 * (hh/ww), 2.0 * (hh/ww), -1.0, 1.0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Aquarium");
    init2D(1.0, 1.0, 1.0);
    glutDisplayFunc(Display);
    //glutReshapeFunc(ChangeSize);
    glutIdleFunc(Display);
    glutMainLoop();
    return 1;
}
