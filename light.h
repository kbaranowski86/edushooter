//3rd party libraries
#include <GL/gl.h>

// Project libraries
#include "point.h"

// definition of light sources
class Light
{
    public:
        point position;
        GLdouble* ambient;
        GLdouble* specular;
        GLdouble* diffuse;

        Light(point, GLdouble*, GLdouble*, GLdouble*);

        void put();
};
