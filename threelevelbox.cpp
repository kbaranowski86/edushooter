#include "threelevelbox.h"

ThreeLevelBox::ThreeLevelBox(point upperLeftBack, point lowerRightFront, char* texturePath):
    Box( upperLeftBack, lowerRightFront, point( 0, 0, 0 ), 0.0f, texturePath ),
    levelHeight( std::fabs( upperLeftBack.GetY() - lowerRightFront.GetY() ) / 3),
    firstPiece( point( upperLeftBack.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), point( lowerRightFront.GetX(), upperLeftBack.GetY() - levelHeight, lowerRightFront.GetZ() ), point( 1, 0, 0 ), 2.0f, texturePath ),
    secondPiece( point( upperLeftBack.GetX(), upperLeftBack.GetY() - levelHeight, upperLeftBack.GetZ()  ), point( lowerRightFront.GetX(), upperLeftBack.GetY() - 2 * levelHeight, lowerRightFront.GetZ() ),  point( 0, 1, 0 ), 4.0f, texturePath ),
    thirdPiece( point( upperLeftBack.GetX(), upperLeftBack.GetY() - 2 * levelHeight, upperLeftBack.GetZ()  ), lowerRightFront,  point( 0, 0, 1 ), 8.0f, texturePath )
{
}

void ThreeLevelBox::Draw()
{
    firstPiece.Draw();
    secondPiece.Draw();
    thirdPiece.Draw();
}

bool ThreeLevelBox::CheckIfHit(Bullet* hittingBullet)
{
    if( firstPiece.CheckIfHit(hittingBullet) )
    {
        Score::GetInstance().IncreasePointsOf( 1 );
        moveDirection = -0.1;

        Box::SetHit( true );
        return true;
    }
    else if( secondPiece.CheckIfHit( hittingBullet ) )
    {
        Score::GetInstance().IncreasePointsOf( 2 );
        moveDirection = -0.1;
        Box::SetHit( true );
        return true;
    }
    else if( thirdPiece.CheckIfHit( hittingBullet ) )
    {
        Score::GetInstance().IncreasePointsOf( 3 );
        moveDirection = -0.1;
        Box::SetHit( true );
        return true;
    }

    return false;
}

void ThreeLevelBox::SetHit( bool hit )
{
    firstPiece.SetHit( hit );
    secondPiece.SetHit( hit );
    thirdPiece.SetHit( hit );

    Box::SetHit( hit );
}

void ThreeLevelBox::MoveAlongY(double y)
{
    firstPiece.MoveAlongY(y);
    secondPiece.MoveAlongY(y);
    thirdPiece.MoveAlongY(y);

    this->MoveBy(point(0, y, 0));
}
