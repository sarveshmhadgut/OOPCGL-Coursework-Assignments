#include<math.h>
#include<GL/glut.h>

float SunX = -0.7;
float SunY = -0.1;
float SunZ = -0.7;

float SunR = 0.2;
float SunG = 0.1;
float SunB = 0.2;

float BgR = 0;
float BgG = 0;
float BgB = 0;

bool flag = true;

void drawSun()
{
    glColor3f(SunR, SunG, SunB);
    glTranslate3f(SunX, SunY, SunZ);
    glSolidSphere(0.2, 30, 30);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
}