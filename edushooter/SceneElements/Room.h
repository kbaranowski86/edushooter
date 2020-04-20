#include "..\BasicShapes\Rect.h"
#include "bullet.h"
#include "..\BasicShapes\Box.h"
#ifndef ROOM_H
#define ROOM_H

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
        Room(Point, Point, Point, const char*);

        bool CheckIfHit(Bullet*);
};
#endif // ROOM_H
