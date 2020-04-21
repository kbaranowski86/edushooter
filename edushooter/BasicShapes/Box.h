//Project libraries
#include "..\SceneElements\Score.h"
#include "Rect.h"
#include "..\SceneElements\InfoBar.h"
#include "..\SceneElements\Bullet.h"
#ifndef BOX_H
#define BOX_H

//definicja prostopadloscianu
class Box
{
      public:
        // upper-left-back point
        Point upperLeftBack;
        // lower-right-front point
        Point lowerRightFront;

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
        Point hitColor;
        double moveDirection;
        const double initialMoveDirection;
        bool hit;
        Point color;
        Point defaultColor;

        std::string texturePath;
        BMPClass textureImage;

        Box(const Point&, const Point&, const Point&, const double&, const std::string& );

        virtual void Draw();
        void MoveBy(const Point&);
        void MoveAlongX(const double&);
        virtual void MoveAlongY(const double&);
        void MoveAlongZ(const double&);
        void SetColor(const double&, const double&, const double&);

        // move Box to desired point handling upperLeftBack (0) or lowerRightFront (1) point
        void MoveTo(const Point&, const bool&);
        void SetColor(const Point&);
        bool GetHit() const;
        virtual void SetHit(const bool&);
        virtual bool CheckIfHit(Bullet&);
};
#endif // BOX_H
