//3rd party libraries
#pragma once

//Project libraries
#include "score.h"

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
        double hitR;
        double hitG;
        double hitB;
        double moveDirection;
        const double initialMoveDirection;
        bool hit;

        char* texturePath;
        BMPClass textureImage;

        Box( point upperLeftBack, point lowerRightFront, double r, double g, double b, double pointsNum, char* texturePath = "" ):
            initialMoveDirection( 0.3 ),
            backWall( upperLeftBack, point(lowerRightFront.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ()), point(0, 0, -1), Utils::XY, texturePath ),
            frontWall( point(upperLeftBack.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ()), lowerRightFront, point(0, 0, 1), Utils::XY, texturePath ),
            leftWall( upperLeftBack, point(upperLeftBack.GetX(), lowerRightFront.GetY(), lowerRightFront.GetZ()), point(-1, 0, 0), Utils::ZY, texturePath ),
            rightWall( point( lowerRightFront.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(1, 0, 0), Utils::ZY, texturePath ),
            topWall( upperLeftBack, point( lowerRightFront.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ() ), point(0, 1, 0), Utils::XZ, texturePath ),
            bottomWall( point( upperLeftBack.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(0, -1, 0), Utils::XZ, texturePath )
        {

                if( texturePath != "" )
                {
                    BMPLoad(texturePath, textureImage);
                }

                //top left back point
                this->upperLeftBack = upperLeftBack;

                // bottom right front point
                this->lowerRightFront = lowerRightFront;

                this->r = r;
                this->g = g;
                this->b = b;
                this->hitR = 0.8;
                this->hitG = 0.8;
                this->hitB = 0.8;

                this->pointsNum = pointsNum;

                hit = false;

                // setting texture
                if( texturePath != "" )
                {
                    this->texturePath = texturePath;
                }

                this->moveDirection = initialMoveDirection;

                width = lowerRightFront.GetX() - upperLeftBack.GetX();
                height = upperLeftBack.GetY() - lowerRightFront.GetY();
                depth = lowerRightFront.GetZ() - upperLeftBack.GetZ();
        }

        virtual void Draw()
        {
            glPolygonMode(GL_FRONT, GL_FILL);
            glPolygonMode(GL_BACK, GL_FILL);

            if( GetHit() == false )
            {
                glColor3f(r, g, b);
            }
            else
            {
                glColor3f(hitR, hitG, hitB);
            }

            backWall.Draw();
            frontWall.Draw();
            leftWall. Draw();
            rightWall.Draw();
            topWall.Draw();
            bottomWall.Draw();
        }

        void MoveBy(point p){
             this->upperLeftBack = this->upperLeftBack + p;
             this->lowerRightFront = this->lowerRightFront + p;
        }

        void MoveAlongX(double x){
             this->MoveBy(point(x, 0, 0));
        }

        virtual void MoveAlongY(double y){
             this->MoveBy(point(0, y, 0));
             backWall.GetUpperLeft()->SetY( upperLeftBack.GetY() );
             backWall.GetLowerRight()->SetY( lowerRightFront.GetY() );
             frontWall.GetUpperLeft()->SetY( upperLeftBack.GetY() );
             frontWall.GetLowerRight()->SetY( lowerRightFront.GetY() );
             leftWall.GetUpperLeft()->SetY( upperLeftBack.GetY() );
             leftWall.GetLowerRight()->SetY( lowerRightFront.GetY() );
             rightWall.GetUpperLeft()->SetY( upperLeftBack.GetY() );
             rightWall.GetLowerRight()->SetY( lowerRightFront.GetY() );
             topWall.GetUpperLeft()->SetY( upperLeftBack.GetY() );
             topWall.GetLowerRight()->SetY( upperLeftBack.GetY() );
             bottomWall.GetUpperLeft()->SetY( lowerRightFront.GetY() );
             bottomWall.GetLowerRight()->SetY( lowerRightFront.GetY() );
        }

        void MoveAlongZ(double z){
             this->MoveBy(point(0, 0, z));
        }

        void SetColor(double r, double g, double b)
        {
             this->r = r;
             this->g = g;
             this->b = b;
        }

        // move Box to desired point handling upperLeftBack (0) or lowerRightFront (1) point
        void MoveTo( point p, bool handler )
        {
            if( handler == 0 )
            {
                upperLeftBack = p;
                lowerRightFront = point( p.GetX() + width, p.GetY() - height, p.GetZ() + depth );
            }
            else
            {
                upperLeftBack = point( p.GetX() - width, p.GetY() + height, p.GetZ() - depth );
                lowerRightFront = p;
            }

            backWall = Rect( upperLeftBack, point(lowerRightFront.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ()), point(0, 0, -1) );
            frontWall = Rect( point(upperLeftBack.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ()), lowerRightFront, point(0, 0, 1) );
            leftWall = Rect( upperLeftBack, point(upperLeftBack.GetX(), lowerRightFront.GetY(), lowerRightFront.GetZ()), point(-1, 0, 0), Utils::ZY );
            rightWall =  Rect( point( lowerRightFront.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(1, 0, 0), Utils::ZY );
            topWall = Rect( upperLeftBack, point( lowerRightFront.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ() ), point(0, 1, 0), Utils::XZ );
            bottomWall = Rect( point( upperLeftBack.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(0, -1, 0), Utils::XZ );
        }

        void SetColor(point vector)
        {
             r = vector.GetX();
             g = vector.GetY();
             b = vector.GetZ();
        }

        bool GetHit()
        {
             return hit;
        }

        virtual void SetHit( bool hit )
        {
             this->hit = hit;
        }

        virtual bool CheckIfHit(Bullet* hittingBullet)
        {
             if( ( hittingBullet->GetPosition().GetX() >= upperLeftBack.GetX() && hittingBullet->GetPosition().GetX() <= lowerRightFront.GetX() )
             && ( hittingBullet->GetPosition().GetY() <= upperLeftBack.GetY() && hittingBullet->GetPosition().GetY() >= lowerRightFront.GetY() )
             && ( hittingBullet->GetPosition().GetZ() >= upperLeftBack.GetZ() && hittingBullet->GetPosition().GetZ() <= lowerRightFront.GetZ() )
             && hittingBullet->GetMomentum() != point(0.0, 0.0, 0.0)
             )
             {
                 if( GetHit() == false )
                 {
                      this->SetHit( true );
                 }

                 moveDirection = -0.1;

                 hittingBullet->GiveMomentum( point(0, 0, 0) );

                 return true;
             }
             return false;
        }
};
