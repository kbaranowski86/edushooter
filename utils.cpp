#include "utils.h"

void Utils::PutTextCamFollowing(point position, point color, void* font, char* str)
{
    glColor3f(color.GetX(), color.GetY(), color.GetZ());

    glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRasterPos3f(position.GetX(), position.GetY(), position.GetZ());
        glNormal3f(0,0,-1);

         // writing text char by char
        char* c;
        for (c = str; *c != '\0'; c++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
    glPopMatrix();
}

void Utils::PutTextStable(point position, point color, void* font, char* str)
{
    glColor3f(color.GetX(), color.GetY(), color.GetZ());

    glRasterPos3f(position.GetX(), position.GetY(), position.GetZ());
    glNormal3f(0,0,-1);

    // writing text char by char
    char* c;
    for (c = str; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}
