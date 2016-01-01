//3rd party libraries
#include <GL/gl.h>

//Project libraries
#include "score.h"
#include "rectangle.h"
#include "infobar.h"
#include "bullet.h"
#ifndef BOX_H
#define BOX_H

//definicja prostopadloscianu
class Box
{
      public:
        // upper-left-back point
        point upperLeftBack;
        // lower-right-front point
        point lowerRightFront;

        double width;
        double height;
        double depth;

        // walls
        Rect backWall;
        Rect frontWall;
        Rect leftWall;
        Rect rightWall;
        Rect topWall;
        Rect bottomWall;

        double pointsNum;
        double r;
        double g;
        double b;
        point hitColor;
        double moveDirection;
        const double initialMoveDirection;
        bool hit;
        point color;
        point defaultColor;

        char* texturePath;
        BMPClass textureImage;

        Box( point, point, point, double, char* );

        virtual void Draw();
        void MoveBy(point);
        void MoveAlongX(double);
        virtual void MoveAlongY(double);
        void MoveAlongZ(double);
        void SetColor(double, double, double);

        // move Box to desired point handling upperLeftBack (0) or lowerRightFront (1) point
        void MoveTo( point, bool );
        void SetColor(point);
        bool GetHit();
        virtual void SetHit( bool );
        virtual bool CheckIfHit(Bullet*);
};
#endif // BOX_H
