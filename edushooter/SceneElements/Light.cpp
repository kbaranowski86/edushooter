#include "Light.h"

Light::Light(Point position, GLdouble* ambient, GLdouble* specular, GLdouble* diffuse)
{
   this->position = position;
   this->ambient = ambient;
   this->specular = specular;
   this->diffuse = diffuse;
}

void Light::put()
{

   GLfloat ambientLight[] = {ambient[0], ambient[1], ambient[2], ambient[3]};
   GLfloat Specular[] = {specular[0], specular[1], specular[2], specular[3]};
   GLfloat Diffuse[] = {diffuse[0], specular[1], specular[2], specular[3]};
   GLfloat lightPos[] = {this->position.GetX(), this->position.GetY(), this->position.GetZ(), 1};
   glEnable(GL_LIGHTING);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight) ;
   glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION,lightPos);
   glEnable(GL_LIGHT0);
}
