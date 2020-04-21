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

      bool camFollowing = false;

      std::string texturePath;
      BMPClass textureImage;
      bool lightingEnable = false;
      Point color;

      Utils::Geometry::Orientation orientation = Utils::Geometry::Orientation::XY;

   public:
      Rect();

      Rect(const Point&, const Point&, const Point&, const Point&, const Utils::Geometry::Orientation&, const string&, const bool& camFollowing = false, const bool& lightingEnable = true);

      void SetColor(const Point&);
      void Draw();
      float GetWidth();
      float GetHeight();

      // move point p, handling upperLeft point (0) (default) or lowerRight point (1)
      void MoveTo(const Point&, const bool& );
      void MoveBy(const Point&);
      void SetCoords(const Point&, const Point&);
      void SetUpperLeft(const Point&);
      void SetLowerRight(const Point&);
      Point& GetUpperLeft();
      Point& GetLowerRight();
};

#endif // RECT_H
