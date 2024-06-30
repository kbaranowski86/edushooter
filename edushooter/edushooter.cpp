#include <windows.h>
#include "Scene.h"

int main(int argc, char** argv)
{
    Scene::InitializeScene(argc, argv);
}

double Scene::tX = 0;
double Scene::tY = 0;
Point Scene::camPosition = Point(0, 0, 12);
int Scene::windowX = 0;
int Scene::windowY = 0;
double Scene::tmpX = 0;
double Scene::tmpY = 0;
BoxSetSet Scene::BSS;
Room Scene::room(Point(-10 , 5, -8), Point(10, -0.99, 20), Point( 1, 1, 1 ), "img\\cegla.bmp");
Weapon Scene::Wpon(Point(camPosition.GetX(), camPosition.GetY(), camPosition.GetZ()), 200, &Scene::BSS, &Scene::room);

//Light arrays of parameters
GLdouble ambient[] = {0.3, 0.3, 0.3, 1};
GLdouble specular[] = {0.4, 0.4, 0.4, 0.4};
GLdouble diffuse[] = {1, 1, 1, 1};

Light Scene::L1 = Light(Point(1,3,5), ambient, specular, diffuse);