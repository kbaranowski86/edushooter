//System libraries
#include <iostream>

//GL libraries
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;



class Bullet{ //definicja pocisku

      public:

             // Position of bullet
             point position;

             // Flag indicating if bullet has a momentum
             point momentum;

             Bullet(){
                      this->momentum = point(0, 0, 0);
                      this->position = point(0, 0, 12);
             }

             Bullet(point startPoint){
                  this->momentum = point(0, 0, 0);
                  this->position = startPoint;
             }

             // Draw bullet
             void Draw()
             {
                  glEnable( GL_LIGHTING );

                  glColor3f(0.5,0.5,0.5);

                  // Move bullet
                  if( momentum != point(0, 0, 0) )
                  {
                      glPushMatrix();
                         glTranslatef( this->position.GetX(), this->position.GetY(), this->position.GetZ() );
                         glutSolidSphere(0.03, 20, 20);
                         glLoadIdentity();
                      glPopMatrix();

                      position = position + momentum / 2.5;
                  }
             }

             point GetPosition()
             {
                return position;
             }

             point GetMomentum()
             {
                return momentum;
             }

             // Give momentum for a bullet
             void GiveMomentum(point momentum)
             {
                this->momentum = momentum;
             }
};
