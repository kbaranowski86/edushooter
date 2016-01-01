// system libraries
#include <windows.h>

// 3rd party libraries
#include <GL/glut.h>
#include <GL/gl.h>

// project libraries
#include "point.h"

#ifndef UTILS_H
#define UTILS_H

class Utils
{
   public:
      enum Orientation{XY, XZ, ZY};

      static void PutTextCamFollowing(point, point, void*, char*);
      static void PutTextStable(point, point, void*, char*);
};

#endif // UTILS_H
