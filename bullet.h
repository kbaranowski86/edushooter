//System libraries
#include <iostream>
#include <windows.h>

//GL libraries
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//project libraries
#include "point.h"
#ifndef BULLET_H
#define BULLET_H

using namespace std;

class Bullet{ //definicja pocisku

      public:

             // Position of bullet
             point position;

             // Flag indicating if bullet has a momentum
             point momentum;

             Bullet();

             Bullet(point startPoint);

             // Draw bullet
             void Draw();

             point GetPosition();

             point GetMomentum();

             // Give momentum for a bullet
             void GiveMomentum(point);
};

#endif // BULLET_H
