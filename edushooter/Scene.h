#pragma once

#include <windows.h>

// Project libraries
#include "SceneElements/Room.h"
#include "SceneElements/InfoBar.h"
#include "SceneElements/BoxSetSet.h"
#include "SceneElements/Weapon.h"
#include "SceneElements/Light.h"

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
        static Point camPosition;
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
