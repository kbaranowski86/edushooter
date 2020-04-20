// system libraries
#include <windows.h>

// 3rd party libraries
#include <GL/glut.h>

// project libraries
#include "..\BasicShapes\Point.h"

#ifndef TEXT_H
#define TEXT_H
namespace Utils
{
    class Text
    {
        public:
            static void PutTextCamFollowing(Point, Point, void*, const char*);
            static void PutTextStable(Point, Point, void*, char*);
    };
}

#endif // TEXT_H
