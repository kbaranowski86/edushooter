// System libraries
#include <iostream>

// projet libraries
#include "bullet.h"
#include "boxsetset.h"
#include "room.h"

// Standard namespaces
using namespace std;

class Weapon
{
      public:

             // weapon position
             point position;

             //collection of bullets
             Bullet *bullets;

             //capacity of magazine
             const int bulletsNum;

             //number of bullet to be launched
             int currentBullet;

             //direction of weapon
             point direction;

             // Set of boxes
             BoxSetSet* boxSetSet;

             // Reference to room
             Room* room;

             Weapon(point, int, BoxSetSet*, Room*);

             void ChangeDirection(double, double);
             void DrawViewFinder();
             void DrawBullets();
             void Shot();
             int GetLastBulletsNum();
};
