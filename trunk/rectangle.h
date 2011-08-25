// 3rd party libraries
#include "BMPLoader.h"

// Project libraries

class Rect
{
   private:
      point upperLeft;
      point lowerRight;
      point normalVector;

      bool camFollowing;

      char* texturePath;
      BMPClass textureImage;

      Utils::Orientation orientation;

   public:

      Rect(){}

      Rect(point upperLeft, point lowerRight, point normalVector, Utils::Orientation orientation = Utils::XY, char* texturePath = "", bool camFollowing = false)
      {
         this->texturePath = texturePath;

         this->camFollowing = camFollowing;

         if( texturePath != "" )
         {
            BMPLoad(texturePath, textureImage);
         }

         this->upperLeft = upperLeft;
         this->lowerRight = lowerRight;
         this->normalVector = normalVector;
         this->orientation = orientation;
      }

      void Draw()
      {
          if( camFollowing == true )
          {
              glPushMatrix();
              glMatrixMode(GL_MODELVIEW);
              glLoadIdentity();
          }

           if( texturePath != "" )
           {
               glEnable(GL_TEXTURE_2D);
               glTexImage2D(GL_TEXTURE_2D, 0, 3, textureImage.width, textureImage.height, 0, GL_RGB,GL_UNSIGNED_BYTE, textureImage.bytes);
           }
           else
           {
               glDisable(GL_TEXTURE_2D);
           }

           glBegin(GL_QUADS);
                    glNormal3f(normalVector.GetX(), normalVector.GetY(), normalVector.GetZ());

                    // 1st point
                    glTexCoord2d(0, 1);
                    glVertex3f(upperLeft.GetX(), upperLeft.GetY(), upperLeft.GetZ());

                    // 2nd point
                    glTexCoord2d(1, 1);
                    if(orientation == Utils::XY || orientation == Utils::XZ)
                    {
                         glVertex3f(lowerRight.GetX(), upperLeft.GetY(), upperLeft.GetZ());
                    }
                    else if(orientation == Utils::ZY)
                    {
                         glVertex3f(upperLeft.GetX(), upperLeft.GetY(), lowerRight.GetZ());
                    }

                    // 3rd point
                    glTexCoord2d(1, 0);
                    if(orientation == Utils::XY)
                    {
                         glVertex3f(lowerRight.GetX(), lowerRight.GetY(), lowerRight.GetZ());
                    }
                    else if(orientation == Utils::XZ)
                    {
                         glVertex3f(lowerRight.GetX(), lowerRight.GetY(), lowerRight.GetZ());
                    }
                    else if(orientation == Utils::ZY)
                    {
                         glVertex3f(lowerRight.GetX(), lowerRight.GetY(), lowerRight.GetZ());
                    }

                    // 4th point
                    glTexCoord2d(0, 0);
                    if(orientation == Utils::XY || orientation == Utils::XZ)
                    {
                         glVertex3f(upperLeft.GetX(), lowerRight.GetY(), lowerRight.GetZ());
                    }
                    else if(orientation == Utils::ZY)
                    {
                         glVertex3f(upperLeft.GetX(), lowerRight.GetY(), upperLeft.GetZ());
                    }
           glEnd();

          if( camFollowing == true )
          {
              glPopMatrix();
          }
      }

      void MoveBy(point p)
      {
           this->upperLeft = this->upperLeft + p;
           this->lowerRight = this->lowerRight + p;
      }

      void SetCoords(point upperLeft, point lowerRight)
      {
           this->upperLeft = upperLeft;
           this->lowerRight = lowerRight;
      }

      void SetUpperLeft(point upperLeft)
      {
           this->upperLeft = upperLeft;
           this->lowerRight = lowerRight;
      }

      void SetLowerRight(point upperLeft)
      {
           this->upperLeft = upperLeft;
           this->lowerRight = lowerRight;
      }

      point* GetUpperLeft()
      {
            return &upperLeft;
      }

      point* GetLowerRight()
      {
            return &lowerRight;
      }
};
