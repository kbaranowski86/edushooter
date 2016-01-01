#include "box.h"

Box::Box( point upperLeftBack, point lowerRightFront, point color, double pointsNum, char* texturePath = "" ):
            initialMoveDirection( 0.3 ),
            backWall( upperLeftBack, point(lowerRightFront.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ()), point(0, 0, -1), color, Utils::XY, texturePath ),
            frontWall( point(upperLeftBack.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ()), lowerRightFront, point(0, 0, 1), color, Utils::XY, texturePath ),
            leftWall( upperLeftBack, point(upperLeftBack.GetX(), lowerRightFront.GetY(), lowerRightFront.GetZ()), point(-1, 0, 0), color, Utils::ZY, texturePath ),
            rightWall( point( lowerRightFront.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(1, 0, 0), color, Utils::ZY, texturePath ),
            topWall( upperLeftBack, point( lowerRightFront.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ() ), point(0, 1, 0), color, Utils::XZ, texturePath ),
            bottomWall( point( upperLeftBack.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(0, -1, 0), color, Utils::XZ, texturePath )
        {
            this->defaultColor = color;

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
                this->hitColor = point( 0.8, 0.8, 0.8 );

                this->pointsNum = pointsNum;

                hit = false;

                // setting texture
                if( texturePath != "" )
                {
                    this->texturePath = texturePath;
                }

                this->moveDirection = initialMoveDirection;

                width = fabs( lowerRightFront.GetX() - upperLeftBack.GetX() );
                height = fabs( upperLeftBack.GetY() - lowerRightFront.GetY() );
                depth = fabs( lowerRightFront.GetZ() - upperLeftBack.GetZ() );
        }

void Box::Draw() {
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    if( GetHit() == true )
    {
        backWall.SetColor( hitColor );
        frontWall.SetColor( hitColor );
        leftWall.SetColor( hitColor );
        rightWall.SetColor( hitColor );
        topWall.SetColor( hitColor );
        bottomWall.SetColor( hitColor );
    }
    else
    {
        backWall.SetColor( defaultColor );
        frontWall.SetColor( defaultColor );
        leftWall.SetColor( defaultColor );
        rightWall.SetColor( defaultColor );
        topWall.SetColor( defaultColor );
        bottomWall.SetColor( defaultColor );
    }

    backWall.Draw();
    frontWall.Draw();
    leftWall. Draw();
    rightWall.Draw();
    topWall.Draw();
    bottomWall.Draw();
}

void Box::MoveBy(point p) {
    this->upperLeftBack = this->upperLeftBack + p;
    this->lowerRightFront = this->lowerRightFront + p;
}

void Box::MoveAlongX(double x) {
    this->MoveBy(point(x, 0, 0));
}

void Box::MoveAlongY(double y){
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

void Box::MoveAlongZ(double z){
    this->MoveBy(point(0, 0, z));
}

void Box::SetColor(double r, double g, double b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

// move Box to desired point handling upperLeftBack (0) or lowerRightFront (1) point
void Box::MoveTo( point p, bool handler )
{
    if( handler == 0 )
    {
        upperLeftBack = p;
    }
    else
    {
        lowerRightFront = p;
    }

    backWall.MoveTo( p, handler );
    frontWall.MoveTo( point( p.GetX(), p.GetY(), p.GetZ() + depth ), handler );
    leftWall.MoveTo( p, handler );
    rightWall.MoveTo( point( p.GetX() + width, p.GetY(), p.GetZ() ), handler );
    topWall.MoveTo( p, handler );
    bottomWall.MoveTo( point( p.GetX(), p.GetY() - height, p.GetZ() ), handler );
}

void Box::SetColor(point vector)
{
    r = vector.GetX();
    g = vector.GetY();
    b = vector.GetZ();
}

bool Box::GetHit()
{
    return hit;
}

void Box::SetHit( bool hit )
{
    this->hit = hit;
}

bool Box::CheckIfHit(Bullet* hittingBullet)
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

        InfoBar::GetInstance().SetHitIndicating();

        return true;
    }
    return false;
}