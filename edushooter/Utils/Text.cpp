#include "Text.h"

void Utils::Text::PutTextCamFollowing(const Point& position, const Point& color, void* font, const std::string& str)
{
    glColor3f(color.GetX(), color.GetY(), color.GetZ());

    glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRasterPos3f(position.GetX(), position.GetY(), position.GetZ());
        glNormal3f(0,0,-1);

         // writing text char by char
        for (char const& c : str)
        {
            glutBitmapCharacter(font, c);
        }
    glPopMatrix();
}

void Utils::Text::PutTextStable(const Point& position, const Point& color, void* font, const std::string& str)
{
    glColor3f(color.GetX(), color.GetY(), color.GetZ());

    glRasterPos3f(position.GetX(), position.GetY(), position.GetZ());
    glNormal3f(0,0,-1);

    // writing text char by char
    for (char const& c : str)
    {
        glutBitmapCharacter(font, c);
    }
}
