#include "Rect.h"
Rect::Rect() {}

Rect::Rect(Point upperLeft, Point lowerRight, Point normalVector, Point color, Utils::Geometry::Orientation orientation = Utils::Geometry::XY, const char* texturePath = NULL, bool camFollowing, bool lightingEnable)
{
    this->color = color;
    this->lightingEnable = lightingEnable;
    this->texturePath = texturePath;
    this->camFollowing = camFollowing;

    if( texturePath != NULL )
    {
        BMPLoad(texturePath, textureImage);
    }

    this->upperLeft = upperLeft;
    this->lowerRight = lowerRight;
    this->normalVector = normalVector;
    this->orientation = orientation;
}

void Rect::SetColor( Point color )
{
    this->color = color;
}

void Rect::Draw()
{
    if( lightingEnable == true )
    {
      glEnable( GL_LIGHTING );
    }
    else
    {
      glDisable( GL_LIGHTING );
    }


    if( camFollowing == true )
    {
      glPushMatrix();
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }

    if( texturePath != NULL )
    {
       glEnable(GL_TEXTURE_2D);
       glTexImage2D(GL_TEXTURE_2D, 0, 3, textureImage.width, textureImage.height, 0, GL_RGB,GL_UNSIGNED_BYTE, textureImage.bytes);
    }
    else
    {
       glDisable(GL_TEXTURE_2D);
    }

    glColor3f( color.GetX(), color.GetY(), color.GetZ() );

    glBegin(GL_QUADS);
        glNormal3f(normalVector.GetX(), normalVector.GetY(), normalVector.GetZ());

        // 1st point
        glTexCoord2d(0, 1);
        glVertex3f(upperLeft.GetX(), upperLeft.GetY(), upperLeft.GetZ());

        // 2nd point
        glTexCoord2d(1, 1);
        if(orientation == Utils::Geometry::XY || orientation == Utils::Geometry::XZ)
        {
            glVertex3f(lowerRight.GetX(), upperLeft.GetY(), upperLeft.GetZ());
        }
        else if(orientation == Utils::Geometry::ZY)
        {
            glVertex3f(upperLeft.GetX(), upperLeft.GetY(), lowerRight.GetZ());
        }

        // 3rd point
        glTexCoord2d(1, 0);
        if(orientation == Utils::Geometry::XY)
        {
            glVertex3f(lowerRight.GetX(), lowerRight.GetY(), lowerRight.GetZ());
        }
        else if(orientation == Utils::Geometry::XZ)
        {
            glVertex3f(lowerRight.GetX(), lowerRight.GetY(), lowerRight.GetZ());
        }
        else if(orientation == Utils::Geometry::ZY)
        {
            glVertex3f(lowerRight.GetX(), lowerRight.GetY(), lowerRight.GetZ());
        }

        // 4th point
        glTexCoord2d(0, 0);
        if(orientation == Utils::Geometry::XY || orientation == Utils::Geometry::XZ)
        {
            glVertex3f(upperLeft.GetX(), lowerRight.GetY(), lowerRight.GetZ());
        }
        else if(orientation == Utils::Geometry::ZY)
        {
            glVertex3f(upperLeft.GetX(), lowerRight.GetY(), upperLeft.GetZ());
        }
    glEnd();

    if( camFollowing == true )
    {
        glPopMatrix();
    }
}

float Rect::GetWidth()
{
    switch( orientation )
    {
        case Utils::Geometry::XY:
            return fabs( this->lowerRight.GetX() - this->upperLeft.GetX() );
            break;

        case Utils::Geometry::XZ:
            return fabs( this->lowerRight.GetX() - this->upperLeft.GetX() );
            break;

        case Utils::Geometry::ZY:
            return fabs( this->lowerRight.GetZ() - this->upperLeft.GetZ() );
    }
}

float Rect::GetHeight()
{
    switch( orientation )
    {
        case Utils::Geometry::XY:
            return fabs( this->upperLeft.GetY() - this->lowerRight.GetY() );
            break;

        case Utils::Geometry::XZ:
            return fabs( this->upperLeft.GetZ() - this->lowerRight.GetZ() );
            break;

        case Utils::Geometry::ZY:
            return fabs( this->upperLeft.GetY() - this->lowerRight.GetY() );
    }
}

// move point p, handling upperLeft point (0) (default) or lowerRight point (1)
void Rect::MoveTo( Point p, bool handle = 0 )
{
    switch( orientation )
    {
        case Utils::Geometry::XY:
            if( handle == 0 )
            {
                SetCoords( p, Point( p.GetX() + GetWidth(), p.GetY() - GetHeight(), p.GetZ() ) );
            }
            else
            {
                SetCoords( Point( p.GetX() - GetWidth(), p.GetY() + GetHeight(), p.GetZ() ), p );
            }

            break;
        case Utils::Geometry::XZ:
            if( handle == 0 )
            {
                SetCoords( p, Point( p.GetX() + GetWidth(), p.GetY(), p.GetZ() + GetHeight() ) );
            }
            else
            {
                SetCoords( Point( p.GetX() - GetWidth(), p.GetY(), p.GetZ() - GetHeight() ), p );
            }
            break;

        case Utils::Geometry::ZY:
            if( handle == 0 )
            {
                SetCoords( p, Point( p.GetX(), p.GetY() - GetHeight(), p.GetZ() + GetWidth() ) );
            }
            else
            {
                SetCoords( Point( p.GetX(), p.GetY() + GetHeight(), p.GetZ() - GetWidth() ), p );
            }
    }
}

void Rect::MoveBy(Point p)
{
   this->upperLeft = this->upperLeft + p;
   this->lowerRight = this->lowerRight + p;
}

void Rect::SetCoords(Point upperLeft, Point lowerRight)
{
   this->upperLeft = upperLeft;
   this->lowerRight = lowerRight;
}

void Rect::SetUpperLeft(Point upperLeft)
{
   this->upperLeft = upperLeft;
   this->lowerRight = lowerRight;
}

void Rect::SetLowerRight(Point upperLeft)
{
   this->upperLeft = upperLeft;
   this->lowerRight = lowerRight;
}

Point* Rect::GetUpperLeft()
{
    return &upperLeft;
}

Point* Rect::GetLowerRight()
{
    return &lowerRight;
}
