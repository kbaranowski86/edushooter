// system libraries
#include <windows.h>

// 3rd party libraries
#include "BMPLoader.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Project libraries
#include "utils.h"
#include "point.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rect
{
   private:
      point upperLeft;
      point lowerRight;
      point normalVector;

      bool camFollowing;

      char* texturePath;
      BMPClass textureImage;
      bool lightingEnable;
      point color;

      Utils::Orientation orientation;

   public:
      Rect();

      Rect(point, point, point, point, Utils::Orientation, char*, bool camFollowing = false, bool lightingEnable = true);

      void SetColor( point );
      void Draw();
      float GetWidth();
      float GetHeight();

      // move point p, handling upperLeft point (0) (default) or lowerRight point (1)
      float MoveTo( point, bool );
      void MoveBy(point);
      void SetCoords(point, point);
      void SetUpperLeft(point);
      void SetLowerRight(point);
      point* GetUpperLeft();
      point* GetLowerRight();
};

#endif // RECT_H
