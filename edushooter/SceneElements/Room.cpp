#include "Room.h"

Room::Room(Point upperLeftBack = Point(0,0,0), Point lowerRightFront = Point(0,0,0), Point color = Point( 0, 0, 0 ), const char* texturePath = "") :
    Box(upperLeftBack, lowerRightFront, color, 0, texturePath),
    backWall(upperLeftBack, Point(lowerRightFront.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ()), color, Point(0, 0, 1), Utils::Geometry::Orientation::XY, texturePath ),
    frontWall(Point(upperLeftBack.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ()), color, lowerRightFront, Point(0, 0, -1), Utils::Geometry::Orientation::XY, texturePath ),
    leftWall(upperLeftBack, Point(upperLeftBack.GetX(), lowerRightFront.GetY(), lowerRightFront.GetZ()), color, Point(1, 0, 0), Utils::Geometry::Orientation::ZY, texturePath ),
    rightWall(Point( lowerRightFront.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), color, lowerRightFront, Point(-1, 0, 0), Utils::Geometry::Orientation::ZY, texturePath ),
    topWall(upperLeftBack, Point( lowerRightFront.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ() ), color, Point(0, 1, 0), Utils::Geometry::Orientation::XZ, texturePath ),
    bottomWall(Point( upperLeftBack.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ() ), color, lowerRightFront, Point(0, -1, 0), Utils::Geometry::Orientation::XZ, texturePath )
{

}

bool Room::CheckIfHit(Bullet* hittingBullet)
{
    if( (hittingBullet->GetPosition().GetX() <= upperLeftBack.GetX() || hittingBullet->GetPosition().GetX() >= lowerRightFront.GetX())
    || (hittingBullet->GetPosition().GetY() >= upperLeftBack.GetY() || hittingBullet->GetPosition().GetY() <= lowerRightFront.GetY())
    || (hittingBullet->GetPosition().GetZ() <= upperLeftBack.GetZ() || hittingBullet->GetPosition().GetZ() >= lowerRightFront.GetZ() )
    )
    {
        hittingBullet->GiveMomentum(Point(0, 0, 0));
        return true;
    }
    return false;
}
