#include "Text.h"

void Utils::Text::PutTextCamFollowing(Point position, Point color, void* font, const char* str)
{
    glColor3f(color.GetX(), color.GetY(), color.GetZ());

    glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRasterPos3f(position.GetX(), position.GetY(), position.GetZ());
        glNormal3f(0,0,-1);

         // writing text char by char
        const char* c;
        for (c = str; *c != '\0'; c++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
    glPopMatrix();
}

void Utils::Text::PutTextStable(Point position, Point color, void* font, char* str)
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
