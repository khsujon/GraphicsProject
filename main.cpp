#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

struct Star
{
    int x;
    int y;
    float twinklingTime;
};

const int NUM_STARS = 50;
Star stars[NUM_STARS];

float currentOffset = 0.0f; // Variable to track the x-offset of the lines representing the current

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set the clear color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 50.0, 0.0, 28.0, -1.0, 1.0); // Set the window size

    // Initialize the stars with random positions and twinkling times
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < NUM_STARS; ++i)
    {
        stars[i].x = rand() % 50;
        stars[i].y = rand() % 10 + 18;
        stars[i].twinklingTime = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0f;
    }
}

void DrawBuilding()
{
    glLineWidth(12.0);
    glBegin(GL_LINES);
    glColor3f(0.3, 0.3, 0.3);   // Ocean blue color for the water
    glVertex2f(0,18);
    glVertex2f(34,16);
    glVertex2f(34,16);
    glVertex2f(50,18);
    glEnd();
    //3rd Building

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.3); // Dark blue color
    glVertex2f(4,22);
    glVertex2f(5.25,22);
    glVertex2f(5.25,20.50);
    glVertex2f(6,20.50);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(6,24);
    glVertex2f(4,24);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4); // Dark blue color
    glVertex2f(6,20.5);
    glVertex2f(6.25,20.5);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(6.25,24.25);
    glVertex2f(6,24.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.4); // Dark blue color
    glVertex2f(4,24);
    glVertex2f(6,24);
    glColor3f(0.4, 0.3, 0.2);
    glVertex2f(6,24.25);
    glVertex2f(4,24.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.3, 0.2); // Dark blue color
    glVertex2f(4,24.25);
    glVertex2f(6,24.25);
    glVertex2f(6,24.5);
    glVertex2f(4,24.5);
    glEnd();

    for (float y = 20.75; y < 22.25; y +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.4, 0.4, 0.4); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(5.5, y);
        glVertex2f(5.75 , y);
        glVertex2f(5.75 , y+0.25);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(5.5 , y+0.25);

        glEnd();
    }

    for (float x = 4.25,y=22.25; x <=5.25; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }

    for (float x = 4.25,y=22.75; x <=5.25; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.6, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glVertex2f(x + 0.25, y+0.25);
        glColor3f(0.3, 0.3, 0.0);
        glVertex2f(x , y+0.25);
        glEnd();
    }

     for (float x = 4.25,y=23.25; x <=5.25; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.4, 0.1);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }





    //1st building
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(3,17.80);
    glVertex2f(5,17.73);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(5,22);
    glVertex2f(3,22);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); // Dark blue color for the sky
    glVertex2f(5,20.50);
    glVertex2f(5.25,20.50);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(5.25,21.75);
    glVertex2f(5,22);
    glEnd();

    for (float x = 3.25; x < 4.75; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.3, 0.3); // Dark blue color for the sky
        glVertex2f(x, 18.5);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, 18.5);
        glVertex2f(x + 0.25, 19.5);
        glVertex2f(x , 19.5);
        glEnd();
    }

    for (float y = 19.75; y < 20.75; y +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.4, 0.4, 0.4); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(3.25, y);
        glVertex2f(4.75 , y);
        glVertex2f(4.75 , y+0.25);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(3.25 , y+0.25);

        glEnd();
    }

    for (float x = 3.25; x < 4.75; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, 21);
        glVertex2f(x + 0.25, 21);
        glColor3f(0.5, 0.5, 0.0);
        glVertex2f(x + 0.25, 21.50);
        glVertex2f(x , 21.50);
        glEnd();
    }

    //2nd building
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.2); // Dark blue color
    glVertex2f(5,17.73);
    glVertex2f(7,17.55);
    glColor3f(0.3, 0.4, 0.4);
    glVertex2f(7,20.50);
    glVertex2f(5,20.50);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4); // Dark blue color
    glVertex2f(7,17.55);
    glVertex2f(7.25,17.53);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(7.25,20.25);
    glVertex2f(7,20.50);
    glEnd();

    for (float x = 5.50,y=19.25; x <=6.75; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }
    for (float x = 5.50,y=19.75; x <=6.75; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }

     for (float y = 18.25; y < 19.25; y +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.7, 0.5, 0.0); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(5.50, y);
        glVertex2f(6.25 , y);
        glVertex2f(6.25  , y+0.25);
        glVertex2f(5.50 , y+0.25);
        glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.5, 0.0); // Dark blue color
    glVertex2f(6.5,18.25);
    glVertex2f(6.75,18.25);
    glColor3f(0.3, 0.4, 0.4);
    glVertex2f(6.75,19);
    glVertex2f(6.5,19);
    glEnd();

    //5th building
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.3); // Dark blue color
    glVertex2f(9.5,21);
    glVertex2f(10,21);
    glVertex2f(10,17.40);
    glVertex2f(12,17.25);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(12,23);
    glVertex2f(9.5,23);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4); // Dark blue color
    glVertex2f(9,21);
    glVertex2f(9.5,21);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(9.5,23);
    glVertex2f(9,22.5);
    glEnd();

    for (float x = 10,y=22.25; x <12; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.5);
        glVertex2f(x + 0.25, y+0.5);
        glVertex2f(x , y+0.5);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.0); // Dark blue color
    glVertex2f(9.25,21.5);
    glVertex2f(9.5,21.75);
    glVertex2f(9.5,22.25);
    glVertex2f(9.25,22);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3); // Dark blue color
    glVertex2f(10,21.5);
    glVertex2f(11.75,21.5);
    glColor3f(0.7, 0.5, 0.0);
    glVertex2f(11.75,22);
    glVertex2f(10,22);
    glEnd();

    for (float x = 10.25,y=19.5; x <=11.5; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }

    for (float x = 10.25,y=20; x <=11.5; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.6, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glVertex2f(x + 0.25, y+0.25);
        glColor3f(0.3, 0.3, 0.0);
        glVertex2f(x , y+0.25);
        glEnd();
    }

     for (float x = 10.25,y=20.5; x <=11.5; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.4, 0.1);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }



    //4th building
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.3); // Dark blue color
    glVertex2f(8,17.5);
    glVertex2f(10,17.40);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(10,21);
    glVertex2f(8,21);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4); // Dark blue color
    glVertex2f(7.75,17.55);
    glVertex2f(8,17.50);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(8,21);
    glVertex2f(7.75,20.5);
    glEnd();
    for (float y = 19.5; y <= 20.75; y +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.4, 0.4); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(8.25, y);
        glVertex2f(9.75 , y);
        glVertex2f(9.75 , y+0.25);
        glColor3f(0.7, 0.7, 0.7);
        glVertex2f(8.25 , y+0.25);

        glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.1, 0.6); // Dark blue color
    glVertex2f(8.5,17.75);
    glVertex2f(8.75,17.75);
    glColor3f(0.3, 0.7, 0.5);
    glVertex2f(8.5,18.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.1, 0.6); // Dark blue color
    glVertex2f(9.25,17.75);
    glVertex2f(9.5,17.75);
    glColor3f(0.3, 0.7, 0.5);
    glVertex2f(9.5,18.75);
    glEnd();


    //Mill
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(13,17.25);
    glVertex2f(20,16.78);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(20,18.75);
    glVertex2f(13,19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.2);
    glVertex2f(13,19);
    glVertex2f(20,18.75);
    glVertex2f(21,19.25);
    glVertex2f(14.75,19.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); // Dark blue color for the sky
    glVertex2f(20,16.78);
    glVertex2f(21,16.75);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(21,19.25);
    glVertex2f(20,18.75);
    glEnd();

    //Mill2
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(15,18.9);
    glVertex2f(19.75,18.75);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(19.75,20);
    glVertex2f(15,20.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.2);
    glVertex2f(15,20.25);
    glVertex2f(19.75,20);
    glVertex2f(20.25,20.25);
    glVertex2f(15.75,20.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); // Dark blue color for the sky
    glVertex2f(19.75,19);
    glVertex2f(20.25,19.25);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(20.25,20.25);
    glVertex2f(19.75,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0); // Dark blue color for the sky
    glVertex2f(17.5,20.25);
    glVertex2f(18,20.25);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(18,22.5);
    glVertex2f(17.5,22.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0); // Dark blue color for the sky
    glVertex2f(18.5,20.25);
    glVertex2f(19,20.25);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(19,23);
    glVertex2f(18.5,23);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.4, 0.1);
    glVertex2f(14,17.2);
    glVertex2f(14.5,17.15);
    glColor3f(0.7, 0.5, 0.0);
    glVertex2f(14.5,18);
    glVertex2f(14,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.3, 0.1);
    glVertex2f(16,17.5);
    glVertex2f(16.75,17.5);
    glColor3f(0.7, 0.5, 0.0);
    glVertex2f(16.75,18);
    glVertex2f(16,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.3, 0.1);
    glVertex2f(18,17.5);
    glVertex2f(18.75,17.5);
    glColor3f(0.7, 0.5, 0.0);
    glVertex2f(18.75,18);
    glVertex2f(18,18);
    glEnd();




    //6th building
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.3); // Dark blue color
    glVertex2f(22,16.75);
    glVertex2f(25,16.5);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(25,23.5);
    glVertex2f(22,23.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4); // Dark blue color
    glVertex2f(25,16.5);
    glVertex2f(25.5,16.5);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(25.5,22.75);
    glVertex2f(25,23.5);
    glEnd();
    for (float x = 22.25,y=21.25; x <=25; x +=0.75)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.5, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.5, y+0.5);
        glVertex2f(x , y+0.5);
        glEnd();
    }
     for (float x = 22.25,y=22.25; x <=25; x +=0.75)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.5, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.5, y+0.5);
        glVertex2f(x , y+0.5);
        glEnd();
    }

    for (float y = 18.5; y < 20.75; y +=0.75)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.4, 0.4); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(22.25, y);
        glVertex2f(24.75 , y);
        glVertex2f(24.75 , y+0.25);
        glColor3f(0.7, 0.7, 0.7);
        glVertex2f(22.25 , y+0.25);
        glEnd();
    }

    //tower
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.2);
    glVertex2f(29.75,24.30);
    glVertex2f(30.25,24.45);
    glVertex2f(30.25,26);
    glVertex2f(29.75,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(29.25,22.90);
    glVertex2f(30.25,23.25);
    glVertex2f(30.5,23.20);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(30.5,24.5);
    glVertex2f(29.25,24.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); // Dark blue color for the sky
    glVertex2f(30.5,23.20);
    glVertex2f(30.75,23.05);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(30.75,24.25);
    glVertex2f(30.5,24.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2); // Dark blue color
    glVertex2f(28.75,21.75);
    glVertex2f(29.75,22);
    glColor3f(0.3, 0.4, 0.4);
    glVertex2f(30.25,21.80);
    glVertex2f(30.25,23.25);
    glVertex2f(28.75,23);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.4); // Dark blue color
    glVertex2f(30.25,21.80);
    glVertex2f(31,21.60);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(31,23);
    glVertex2f(30.25,23.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.3); // Dark blue color
    glVertex2f(28.25,20.5);
    glVertex2f(28.5,20);
    glVertex2f(28.5,16.30);
    glVertex2f(29.75,16.25);
    glColor3f(0.4, 0.3, 0.3);
    glVertex2f(29.75,22);
    glVertex2f(28.25,21.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4); // Dark blue color
    glVertex2f(29.75,16.25);
    glVertex2f(31.25,16.20);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(31.25,21.5);
    glVertex2f(29.75,22);
    glEnd();

    for (float y = 19.25; y <=21.25; y +=1.25)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.4, 0.4); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(28.75, y);
        glVertex2f(29.25 , y+0.25);
        glVertex2f(29.25 , y+0.75);
        glColor3f(0.7, 0.7, 0.7);
        glVertex2f(28.75 , y+0.5);
        glEnd();
    }

    for (float y = 19.25; y <=21.25; y +=1.25)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.4, 0.4); // Dark blue color for the sky
        //glColor3f(0.3, 0.4, 0.4); // Dark blue color for the sky
        glVertex2f(30, y+0.25);
        glVertex2f(30.5 , y);
        glVertex2f(30.5 , y+0.5);
        glColor3f(0.7, 0.7, 0.7);
        glVertex2f(30 , y+0.75);
        glEnd();
    }
    for (float x = 29,y=22.5; x <30; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.5, 0.0);
    glVertex2f(29.5,23.75);
    glVertex2f(30.25,23.75);
    glVertex2f(30.25,24);
    glVertex2f(29.5,24);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(0.1, 0.1, 0.1);   // Ocean blue color for the water
    glVertex2f(30,26);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(30,27.75);
    glEnd();



    //7th building
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(25.5,16.5);
    glVertex2f(28,16.25);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(28,20.75);
    glVertex2f(25.5,20.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); // Dark blue color for the sky
    glVertex2f(28,16.25);
    glVertex2f(28.5,16.30);
    glColor3f(0.3, 0.3, 0.4);
    glVertex2f(28.5,20);
    glVertex2f(28,20.75);
    glEnd();
    for (float x = 26,y=19.25; x <28; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glColor3f(0.7, 0.5, 0.0);
        glVertex2f(x + 0.25, y+0.25);
        glVertex2f(x , y+0.25);
        glEnd();
    }

    for (float x = 26,y=19.75; x <28; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.6, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glVertex2f(x + 0.25, y+0.25);
        glColor3f(0.3, 0.3, 3.0);
        glVertex2f(x , y+0.25);
        glEnd();
    }
     for (float x = 26,y=17.75; x <27; x +=0.5)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.4, 0.4);
        glVertex2f(x, y);
        glVertex2f(x + 0.25, y);
        glVertex2f(x + 0.25, y+0.75);
        glColor3f(0.3, 0.3, 3.0);
        glVertex2f(x , y+0.75);
        glEnd();
    }


}

// Define a global variable to track the current x-coordinate of the circle
float circleX = 0.0f;

// DrawCircle function with animation
void DrawCloud(float centerX, float centerY, float radius)
{
    // Calculate the x-coordinate of the circle with the current circleX value
    float x = centerX + circleX;

    int numSegments = 100;
    float angleStep = 2 * 3.14159 / numSegments;

    // Set the cloud color for the circle


    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = i * angleStep;
        float xPos = x + radius * cos(angle);
        float yPos = centerY + radius * sin(angle);
        glVertex2f(xPos, yPos);
    }
    glEnd();
}

// Update function to handle the animation
void UpdateCloud()
{
    // Adjust the circleX based on the desired animation speed
    float speed = 0.005f; // Adjust this value to control the speed of the animation
    circleX += speed;

    // Wrap the circleX when it reaches the end of the screen
    float screenWidth = 50.0f;
    if (circleX > screenWidth)
        circleX -= screenWidth;

    float stopX = 33.5f; // Adjust this value to set the desired stop point
    if (circleX >= stopX)
    {
        // Reset the circleX to the stop point
        circleX = stopX;
        // Optionally, you can also set the speed to 0 to completely stop the movement
        // speed = 0.0f;
    }
}

float boatX = 0.0f;

void DrawBoat()
{
    // Calculate the x-coordinate of the boat with the current boatX value
    float x = boatX;

    // boat bottom
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f); // Boat bottom color (dark blue)
    glVertex2f(1.75 + x, 10.75);
    glVertex2f(4 + x, 10.75);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(5.75 + x, 12);
    glVertex2f(0 + x, 12);
    glEnd();

    //boat top1
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f); // Light beige color for the second floor
    glVertex2f(2 + x, 12);
    glVertex2f(4.5 + x, 12);
    glVertex2f(4.5 + x, 12.75);
    glVertex2f(2 + x, 12.75);
    glEnd();

    //boat top2
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(2.75 + x, 12.75);
    glVertex2f(4.25 + x, 12.75);
    glVertex2f(4.25 + x, 13.5);
    glVertex2f(2.75 + x, 13.5);
    glEnd();

    //boat top3
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.3f, 0.3f);
    glVertex2f(3.25 + x, 13.5);
    glVertex2f(3.75 + x, 13.5);
    glVertex2f(3.75 + x, 14.25);
    glVertex2f(3.25 + x, 14.25);
    glEnd();

    //boat top1 window
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); // Light gray color for the window
    glVertex2f(2.5 + x, 12.25);
    glVertex2f(2.75 + x, 12.25);
    glVertex2f(2.75 + x, 12.5);
    glVertex2f(2.5 + x, 12.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); // Light gray color for the window
    glVertex2f(3.25 + x, 12.25);
    glVertex2f(3.5 + x, 12.25);
    glVertex2f(3.5 + x, 12.5);
    glVertex2f(3.25 + x, 12.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); // Light gray color for the window
    glVertex2f(4 + x, 12.25);
    glVertex2f(4.25 + x, 12.25);
    glVertex2f(4.25 + x, 12.5);
    glVertex2f(4 + x, 12.5);
    glEnd();

    //boat top2 window
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0); // Light gray color for the window
    glVertex2f(2.75 + x, 12.5);
    glVertex2f(3 + x, 12.5);
    glVertex2f(3 + x, 12.75);
    glVertex2f(2.75 + x, 12.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); // Light gray color for the window
    glVertex2f(3.25 + x, 12.5);
    glVertex2f(3.5 + x, 12.5);
    glVertex2f(3.5 + x, 12.75);
    glVertex2f(3.25 + x, 12.75);
    glEnd();

    //boat top3 window
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0); // Light gray color for the window
    glVertex2f(3.5 + x, 12.75);
    glVertex2f(3.75 + x, 12.75);
    glVertex2f(3.75 + x, 13);
    glVertex2f(3.5 + x, 13);
    glEnd();

    //boat flash
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); // Dark blue color for the sky
    glVertex2f(5.50+x, 11.75);
    glVertex2f(7.25+x, 11);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(7.50+x, 11.50);
    glEnd();

    // Update the boat's x-coordinate for the next frame
    boatX += 0.0038f; // Adjust the speed of the boat by changing the increment value
    if (boatX > 50.0f)
        boatX = 0.0f;
}

//car draw
void DrawWhile(float cX, float cY, float r, int nS)
{
    glColor3f(1.0f, 0.9f, 0.8f); // Set color to car while
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cX, cY); // Center of the circle
    for (int i = 0; i <= nS; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(nS); // Angle for each segment
        float x = r * cosf(theta); // Calculate x-coordinate
        float y = r * sinf(theta); // Calculate y-coordinate
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(cX + x, cY + y); // Vertex position
    }
    glEnd();
}
float carX=50;
void DrawCar()
{
    float x=carX;

    DrawWhile(x-2.0,7.25,0.25,100);
    DrawWhile(x-3.50,7.25,0.25,100);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.4f, 0.1f); // Boat bottom color (dark blue)
    glVertex2f(x-1, 7.25);
    glVertex2f(x-1, 7.75);
    glVertex2f(x-1.5, 7.75);
    glVertex2f(x-2, 8.25);
    glVertex2f(x-3.75, 8.25);
    glVertex2f(x-4, 7.75);
    glVertex2f(x-5, 7.75);
    glVertex2f(x-5, 7.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(x-2, 7.75);
    glVertex2f(x-2.25, 8);
    glVertex2f(x-2.75, 8);
    glVertex2f(x-2.75, 7.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(x-3, 7.75);
    glVertex2f(x-3, 8);
    glVertex2f(x-3.5, 8);
    glVertex2f(x-3.6, 7.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(x-5, 7.5);
    glVertex2f(x-6.5, 7.5);
    glColor3f(0.7f, 0.7f, .0f);
    glVertex2f(x-6.25, 7);
    glEnd();

    carX-=0.01f;

    if(carX<0)
        carX=50;

}

void DrawBridge()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4); // Dark brown color for the bridge at night
    glVertex2i(0, 6);
    glVertex2i(50, 6);
    glVertex2i(50, 8);
    glVertex2i(0, 8);
    glEnd();



    for (int x = 0; x < 50; x += 3)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.8, 0.8); // Dark brown color for the bridge at night
        glVertex2i(x, 6);
        glVertex2i(x + 1, 6);
        glVertex2i(x + 3, 8);
        glVertex2i(x + 2, 8);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.4, 0.0); // Dark brown color for the bridge at night
    glVertex2f(0, 8);
    glVertex2f(50, 8);
    glVertex2f(50, 8.5);
    glVertex2f(0, 8.5);
    glEnd();

    for (int x = 1; x < 50; x +=3)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0); // Dark brown color for the bridge at night
        glVertex2f(x, 8);
        glVertex2f(x + 0.25, 8);
        glVertex2f(x + 0.5, 8.50);
        glVertex2f(x + 0.25, 8.50);
        glEnd();
    }

    DrawCar();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);   // Ocean blue color for the water
    glVertex2f(4,6);
    glVertex2f(4,8.75);
    glVertex2f(4,8.75);
    glVertex2f(4.75,8.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(4.75,8.5);
    glVertex2f(4.5,8.25);
    glVertex2f(5,8.25);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);   // Ocean blue color for the water
    glVertex2f(14,8);
    glVertex2f(14,9.75);
    glVertex2f(14,9.75);
    glVertex2f(13,9.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(13,9.25);
    glVertex2f(13.25,9);
    glVertex2f(12.75,9);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);   // Ocean blue color for the water
    glVertex2f(21,6);
    glVertex2f(21,8.75);
    glVertex2f(21,8.75);
    glVertex2f(21.75,8.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(21.75,8.5);
    glVertex2f(21.5,8.25);
    glVertex2f(22,8.25);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);   // Ocean blue color for the water
    glVertex2f(33,8);
    glVertex2f(33,9.75);
    glVertex2f(33,9.75);
    glVertex2f(32,9.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(32,9.25);
    glVertex2f(32.25,9);
    glVertex2f(31.75,9);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);   // Ocean blue color for the water
    glVertex2f(42,6);
    glVertex2f(42,8.75);
    glVertex2f(42,8.75);
    glVertex2f(42.75,8.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(42.75,8.5);
    glVertex2f(42.5,8.25);
    glVertex2f(43,8.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0); // Dark brown color for the bridge at night
    glVertex2f(0, 6.75);
    glVertex2f(50, 6.75);
    glVertex2f(50, 7);
    glVertex2f(0, 7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.4, 0.0); // Dark brown color for the bridge at night
    glVertex2f(0, 6);
    glVertex2f(50, 6);
    glVertex2f(50, 6.75);
    glVertex2f(0., 6.75);
    glEnd();

    for (int x = 0; x < 50; x +=3)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0); // Dark brown color for the bridge at night
        glVertex2f(x, 6.75);
        glVertex2f(x + 0.25, 6.75);
        glVertex2f(x + 0.5, 7);
        glVertex2f(x + 0.25, 7);
        glEnd();
    }

    //bridge big stand
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.6, 0.6, 0.6);   // Ocean blue color for the water
    glVertex2f(24,6);
    glVertex2f(24,11);
    glVertex2f(24,11);
    glVertex2f(25,14);
    glVertex2f(25,14);
    glVertex2f(25,8.50);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    //Bridge mini stand
    glLineWidth(5.0);
    glVertex2f(12,6);
    glVertex2f(12,8.50);
    glVertex2f(12,8.50);
    glVertex2f(12.75,11);
    glVertex2f(12.75,11);
    glVertex2f(12.75,8.50);

    glVertex2f(38,6);
    glVertex2f(38,8.25);
    glVertex2f(38,8.25);
    glVertex2f(38.75,10.75);
    glVertex2f(38.75,10.75);
    glVertex2f(38.75,8.50);
    //Bridge rope
    glVertex2f(0,6);
    glVertex2f(24,11);
    glVertex2f(24,11);
    glVertex2f(50,6);

    glVertex2f(2.25,8.50);
    glVertex2f(25,14);
    glVertex2f(25,14);
    glVertex2f(47.75,8.50);

    glEnd();



}





void DrawMoon()
{
    int moonRadius = 1;
    int moonX = 38;
    int moonY = 26;

    int numSegments = 100;
    float angleStep = 2 * 3.14159 / numSegments;

    glColor3f(0.9f, 0.9f, 0.7f); // Light gray color with a slight yellowish tint for the moon

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(moonX, moonY); // Center point of the moon
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = i * angleStep;
        float x = moonX + moonRadius * cos(angle);
        float y = moonY + moonRadius * sin(angle);

        glVertex2f(x, y);
    }
    glEnd();
}

void star()
{
    // Draw twinkling stars in the sky
    glColor3f(1.0, 1.0, 0.0); // Sparkling color for glitter

    glPointSize(2.0); // Set the initial size of the points

    float currentTime = static_cast<float>(clock()) / CLOCKS_PER_SEC;

    for (int i = 0; i < NUM_STARS; ++i)
    {
        float starSize = (std::sin((currentTime + stars[i].twinklingTime) * 5.0) > 0.0) ? 2.0 : 1.0;
        glPointSize(starSize); // Set the size of the points

        glBegin(GL_POINTS);
        glVertex2i(stars[i].x, stars[i].y);
        glEnd();
    }

    glColor3f(1.0, 1.0, 0.0); // Sparkling color for glitter
    glPointSize(3.0); // Set the size of the glitter points

    glBegin(GL_POINTS);
    // Draw more stars
    glVertex2i(5, 25);
    glVertex2i(10, 20);
    glVertex2i(15, 24);
    glVertex2i(20, 26);
    glVertex2i(25, 22);
    glVertex2i(30, 24);
    glVertex2i(35, 20);
    glVertex2i(40, 25);
    glVertex2i(45, 23);
    glVertex2i(48, 26);
    glEnd();
}

void DrawCurrent()
{
    // Calculate the x-offset based on the current position
    float xOffset = currentOffset;
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.5, 1.0);   // Ocean blue color for the water

    // Draw the lines with an increasing x-offset
    for (float x = 0.0f; x <= 6.5f; x += 0.5f)
    {
        glVertex2f(x + xOffset, 11.0f);
        glVertex2f(x + 0.5f + xOffset, 11.5f);
        glVertex2f(x + 0.5f + xOffset, 11.5f);
        glVertex2f(x + 1.0f + xOffset, 11.0f);
    }

     for (float x = 0.0f; x <= 5.5f; x += 0.5f)
    {
        glVertex2f(x + xOffset, 10.25f);
        glVertex2f(x + 0.5f + xOffset, 10.75f);
        glVertex2f(x + 0.5f + xOffset, 10.75f);
        glVertex2f(x + 1.0f + xOffset, 10.25f);
    }

      for (float x = 1.5f; x <= 7.5f; x += 0.5f)
    {
        glVertex2f(x + xOffset, 9.5f);
        glVertex2f(x + 0.5f + xOffset, 10.0f);
        glVertex2f(x + 0.5f + xOffset, 10.0f);
        glVertex2f(x + 1.0f + xOffset, 9.5f);
    }

    glEnd();
}

void DrawScreen()
{
    // Draw the upper half with a starry sky
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.2); // Dark blue color for the sky
    glVertex2i(0, 18);
    glVertex2i(34, 16);
    glVertex2i(50, 18);
    glVertex2i(50, 28);
    glVertex2i(0, 28);
    glEnd();




    // Draw the lower half with river water
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.2);   // Dark blue color for the water
    glVertex2i(0, 0);           // Vertex 1
    glVertex2i(50, 0);          // Vertex 2
    glColor3f(0.0, 0.0, 0.4);   // Light blue color for the water
    glVertex2i(50, 18);         // Vertex 3
    glVertex2i(34, 16);         // Vertex 4
    glVertex2i(0, 18);          // Vertex 5
    glEnd();

    DrawCurrent();

}

void Update()
{
    // Adjust the currentOffset based on the elapsed time
    float speed = 0.0038f; // Adjust this value to control the speed of the animation
    currentOffset += speed ;

    // Wrap the currentOffset when it reaches the end of the screen
    float screenWidth = 50.0f;
    if (currentOffset > screenWidth)
        currentOffset -= screenWidth;
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);



    // Update the animation
    Update();

    DrawScreen();
    star();
    DrawMoon(); // Draw the moon in the sky

    DrawBoat();
    DrawBridge();

    UpdateCloud();
    glColor3f(0.4f, 0.5f, 0.5f); // Set color for darkish cloud
    DrawCloud(3.0,26.0,0.5);
    DrawCloud(3.25,25.5,0.5);
    DrawCloud(2.75,25.5,0.5);
    DrawCloud(3.75,25.50,0.5);
    DrawCloud(2.25,25.50,0.5);

    glColor3f(0.4f, 0.4f, 0.5f); // Set color for darkish cloud
    DrawCloud(5.0,25.0,0.5);
    DrawCloud(5.25,24.5,0.5);
    DrawCloud(4.75,24.5,0.5);
    DrawCloud(5.75,24.50,0.5);
    DrawCloud(4.25,24.50,0.5);

    DrawBuilding();



    glutSwapBuffers();
}

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, Timer, 0); // 60 FPS (1000ms / 60 = 16.67ms)
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    int height = GetSystemMetrics(SM_CYSCREEN);
    int width = GetSystemMetrics(SM_CXSCREEN);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(width, height);
    glutCreateWindow("Final Project");
    init();
    glutTimerFunc(0, Timer, 0);
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw); // Set the Draw function as the idle function for continuous rendering
    glutMainLoop();
    return 0;
}



