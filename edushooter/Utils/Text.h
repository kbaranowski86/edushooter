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
            static void PutTextCamFollowing(const Point&, const Point&, void*, const char*);
            static void PutTextStable(const Point&, const Point&, void*, char*);
    };
}

#endif // TEXT_H
