//Project libraries
#include <windows.h>
#include "scene.h"

int main(void)
{
    Scene::InitializeScene();
}

double Scene::tX = 0;
double Scene::tY = 0;
point Scene::camPosition = point(0, 0, 12);
int Scene::windowX = 0;
int Scene::windowY = 0;
double Scene::tmpX = 0;
double Scene::tmpY = 0;
BoxSetSet Scene::BSS;
Room Scene::room(point(-10 , 5, -8), point(10, -0.99, 20), 1, 1, 1, "cegla.bmp");
Weapon Scene::Wpon(point(camPosition.GetX(), camPosition.GetY(), camPosition.GetZ()), 200, &Scene::BSS, &Scene::room);

//Light arrays of parameters
GLdouble ambient[] = {0.3, 0.3, 0.3, 1};
GLdouble specular[] = {0.4, 0.4, 0.4, 0.4};
GLdouble diffuse[] = {1, 1, 1, 1};

Light Scene::L1 = Light(point(1,3,5), ambient, specular, diffuse);
