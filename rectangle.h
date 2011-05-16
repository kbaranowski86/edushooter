// Project libraries

class Rect
{
   private:
      point upperLeft;
      point lowerRight;

      point normalVector;

      Utils::Orientation orientation;

   public:

      Rect(){}

      Rect(point upperLeft, point lowerRight, point normalVector, Utils::Orientation orientation = Utils::XY)
      {
             this->upperLeft = upperLeft;
             this->lowerRight = lowerRight;
             this->normalVector = normalVector;
             this->orientation = orientation;
      }

      void Draw()
      {
           glBegin(GL_QUADS);
                    glNormal3f(normalVector.GetX(), normalVector.GetY(), normalVector.GetZ());

                    // 1st point
                    glVertex3f(upperLeft.GetX(), upperLeft.GetY(), upperLeft.GetZ());

                    // 2nd point
                    if(orientation == Utils::XY || orientation == Utils::XZ)
                    {
                         glVertex3f(lowerRight.GetX(), upperLeft.GetY(), upperLeft.GetZ());
                    }
                    else if(orientation == Utils::ZY)
                    {
                         glVertex3f(upperLeft.GetX(), upperLeft.GetY(), lowerRight.GetZ());
                    }

                    // 3rd point
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
                    if(orientation == Utils::XY || orientation == Utils::XZ)
                    {
                         glVertex3f(upperLeft.GetX(), lowerRight.GetY(), lowerRight.GetZ());
                    }
                    else if(orientation == Utils::ZY)
                    {
                         glVertex3f(upperLeft.GetX(), lowerRight.GetY(), upperLeft.GetZ());
                    }
           glEnd();
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
