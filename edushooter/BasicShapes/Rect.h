// system libraries
#include <windows.h>

// 3rd party libraries
#include "..\Utils\BMPLoader.h"
#include <GL/glut.h>
#include <GL/glu.h>

// Project libraries
#include "..\Utils\Geometry.h"
#include "..\Utils\text.h"
#include "Point.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rect
{
   private:
      Point upperLeft;
      Point lowerRight;
      Point normalVector;

      bool camFollowing;

      const char* texturePath;
      BMPClass textureImage;
      bool lightingEnable;
      Point color;

      Utils::Geometry::Orientation orientation;

   public:
      Rect();

      Rect(Point, Point, Point, Point, Utils::Geometry::Orientation, const char*, bool camFollowing = false, bool lightingEnable = true);

      void SetColor( Point );
      void Draw();
      float GetWidth();
      float GetHeight();

      // move point p, handling upperLeft point (0) (default) or lowerRight point (1)
      void MoveTo( Point, bool );
      void MoveBy(Point);
      void SetCoords(Point, Point);
      void SetUpperLeft(Point);
      void SetLowerRight(Point);
      Point* GetUpperLeft();
      Point* GetLowerRight();
};

#endif // RECT_H
