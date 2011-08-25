class Room : public Box
{

    // walls
    Rect backWall;
    Rect frontWall;
    Rect leftWall;
    Rect rightWall;
    Rect topWall;
    Rect bottomWall;

      public:
          Room(point upperLeftBack = point(0,0,0), point lowerRightFront=point(0,0,0), float r = 0, float g = 0, float b = 0, char* texturePath = "") :
            Box(upperLeftBack, lowerRightFront, r, g, b, 0, texturePath),
            backWall( upperLeftBack, point(lowerRightFront.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ()), point(0, 0, 1), Utils::XY, texturePath ),
            frontWall( point(upperLeftBack.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ()), lowerRightFront, point(0, 0, -1), Utils::XY, texturePath ),
            leftWall( upperLeftBack, point(upperLeftBack.GetX(), lowerRightFront.GetY(), lowerRightFront.GetZ()), point(1, 0, 0), Utils::ZY, texturePath ),
            rightWall( point( lowerRightFront.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(-1, 0, 0), Utils::ZY, texturePath ),
            topWall( upperLeftBack, point( lowerRightFront.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ() ), point(0, 1, 0), Utils::XZ, texturePath ),
            bottomWall( point( upperLeftBack.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ() ), lowerRightFront, point(0, -1, 0), Utils::XZ, texturePath )
          {

          }

          bool CheckIfHit(Bullet* hittingBullet)
          {
                 if( (hittingBullet->GetPosition().GetX() <= upperLeftBack.GetX() || hittingBullet->GetPosition().GetX() >= lowerRightFront.GetX())
                 || (hittingBullet->GetPosition().GetY() >= upperLeftBack.GetY() || hittingBullet->GetPosition().GetY() <= lowerRightFront.GetY())
                 || (hittingBullet->GetPosition().GetZ() <= upperLeftBack.GetZ() || hittingBullet->GetPosition().GetZ() >= lowerRightFront.GetZ() )
                 )
                 {
                     hittingBullet->GiveMomentum(point(0, 0, 0));
                     return true;
                 }
                 return false;
          }
};
