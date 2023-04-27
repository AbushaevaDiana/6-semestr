#include <GL/glut.h>
#include<bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#define DEG2RAD 3.14159 / 180.0

using namespace std;

const float colors[10][3] = {{1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 0},
    {1, 0, 1},
    {0, 1, 1},
    {0.5, 0.3, 0.2},
    {0.2, 0.6, 0.8},
    {0.3, 0.9, 0.1},
    {0.8, 0.2, 0.7}
};

float fish1_move = 0.0f;
int fish1_flag = 1;

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_PROJECTION);
    glDepthFunc(GL_LEQUAL);
    gluOrtho2D(-800.0, 800.0, -600.0, 600.0);
}

void DrawEllipse(float x, float y, float radiusX, float radiusY)
{
    register int i;
    register float rad ;
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++)
    {
        glVertex2f(x + cos(i * DEG2RAD) * radiusX, y + sin(i * DEG2RAD) * radiusY);
    }
    glEnd();
}

//Water backgorund
void water()
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
void stone1(float x, float y)
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
    glutSwapBuffers();

}

//Stone 2
void stone2(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.1,0.003);
    DrawEllipse(x, y, 4*y, y*2);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();

}

//Stone 3
void stone3(float x, float y)
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
    glutSwapBuffers();
}

//Stone 4
void stone4(float x, float y)
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
    glutSwapBuffers();
}

//Stone 5
void stone5(float x, float y)
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
    glutSwapBuffers();
}

//Plant
void plant(float x, float y)
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-800.0f, -600.0f, 1.0f);

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
    glutSwapBuffers();
}

//Fish1
void fish1(float x, float y, int color, float rx, float ry)
{
    glLoadIdentity();
    glPushMatrix();

    if(fish1_flag == 1)
    {
        glTranslatef(-1*fish1_move, 0.0f, 0.0f);
    }
    else
    {
        glTranslatef(fish1_move, 0.0f, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
    }

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
    glutSwapBuffers();

}

//Fish2
void fish2(float x, float y, int color, float rx, float ry)
{
    glLoadIdentity();
    glPushMatrix();

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
    glColor3f(0.0, 0.0, 0.0);
    DrawEllipse(x-50.0, y+20.0, ry/2, ry/2);
    glColor3f(1.0, 1.0, 1.0);
    DrawEllipse(x-40.0, y+30.0, ry/8, ry/8);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

//Fish3
void fish3(float x, float y, int color)
{
    glLoadIdentity();
    glPushMatrix();

    //Tail
    glBegin(GL_POLYGON);
    glColor3f(color*0.1, color*0.2, color*0.3);
    glVertex3f(x+50, y, 0.0);
    glColor3f(color*0.01, color*0.02, color*0.03);
    glVertex3f(x+110.0, y+50.0, 0.0);
    glColor3f(color*0.001, color*0.002, color*0.003);
    glVertex3f(x+160.0, y+20.0, 0.0);
    glVertex3f(x+130.0, y, 0.0);
    glVertex3f(x+160, y-20.0, 0.0);
    glColor3f(color*0.01, color*0.02, color*0.03);
    glVertex3f(x+110.0, y-50.0, 0.0);
    glColor3f(color*0.1, color*0.2, color*0.3);
    glVertex3f(x+50, y, 0.0);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
        glVertex3f(x-80.0, y, 0.0);
        glVertex3f(x+80.0, y+150.0, 0.0);
        glVertex3f(x+80.0, y-150.0, 0.0);
        glVertex3f(x-80.0, y, 0.0);
    glEnd();

   //Eye
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    DrawEllipse(x-50.0, y+20.0, 20, 20);
    glColor3f(1.0, 1.0, 1.0);
    DrawEllipse(x-40.0, y+30.0, 5, 5);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();

}

void animation(int value) {
    srand(time(NULL));
    fish1_move+=1.0f;

    if(fish1_move>300 && fish1_flag!=0)
    {
        fish1_move-=300;
        fish1_flag = 0;
    }
    else if(fish1_move>300 && fish1_flag==0)
    {
        fish1_move-=300;
        fish1_flag = 1;
    }

}

//Displaying elements
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //animation();
    water();
    stone2(1400, 20);
    stone4(240, 25);
    stone2(100, 10);
    stone2(800, 20);
    stone1(60, 110);
    stone3(550, 110);
    stone4(900, 20);
    plant(600, 130);
    plant(300, 120);
    plant(0, 200);
    plant(1200, 200);
    plant(1500, 80);
    plant(1900, 240);
    stone1(700, 90);
    stone5(1040, 20);
    stone5(430, 20);
    
    fish1(350, 400, 5, 150, 40);
    fish1(-600, 300, 7, 150, 40);
    fish2(-270, 500, 6, 120, 80);
    fish3(-400, -100, 1);
    glFlush();
    glutSwapBuffers();
    
}


int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Aquarium");
    init2D(1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
