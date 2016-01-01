#include "rectangle.h"
#include "bullet.h"
#include "box.h"
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
        Room(point, point, point, char*);

        bool CheckIfHit(Bullet*);
};
#endif // ROOM_H
