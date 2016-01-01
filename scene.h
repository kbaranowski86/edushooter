#pragma once

#include <windows.h>

// Project libraries
#include "room.h"
#include "infobar.h"
#include "boxsetset.h"
#include "weapon.h"
#include "light.h"

//System libraries
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES

//---------------------------------------------------------------------------

using namespace std;

// Container for all the logic of game
class Scene
{
    public:
        static Light L1;
        static BoxSetSet BSS;
        static Room room;
        static Weapon Wpon;
        static double tX, tY;
        static point camPosition;
        static int windowX, windowY;
        static double tmpX, tmpY;

        // Initializing all neccessary objects
        static void InitializeScene();

   private:

      // Draw objects on scene
      static void DrawObjects();

      //odrysowanie przy przesuniêciu b¹dŸ zmianie rozmiaru okna
      static void Reshape(int, int);

      // Refreshing display
      static void Idle(int);

      //Mouse move event
      static void MouseMotion(int, int);

      //Mouse click event
      static void MouseClick(int, int, int, int);

      //Keyboard key pressed event
      static void KeyPressed(unsigned char, int, int);

      static void Display(void);
};
