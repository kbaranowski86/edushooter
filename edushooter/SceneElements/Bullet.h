//System libraries
#include <iostream>
#include <windows.h>

//GL libraries
#include <GL/glut.h>
#include <GL/glu.h>

//project libraries
#include "..\BasicShapes\Point.h"
#ifndef BULLET_H
#define BULLET_H

using namespace std;

class Bullet{ //definicja pocisku

      public:

             // Position of bullet
             Point position;

             // Flag indicating if bullet has a momentum
             Point momentum;

             Bullet();

             Bullet(Point startPoint);

             // Draw bullet
             void Draw();

             Point GetPosition();

             Point GetMomentum();

             // Give momentum for a bullet
             void GiveMomentum(Point);
};

#endif // BULLET_H
