// Project libraries
#include "..\BasicShapes\Point.h"

// definition of light sources
class Light
{
    public:
        Point position;
        GLdouble* ambient;
        GLdouble* specular;
        GLdouble* diffuse;

        Light(Point, GLdouble*, GLdouble*, GLdouble*);

        void put();
};
