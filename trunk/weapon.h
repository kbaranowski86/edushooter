// System libraries
#include <iostream>

// Project libraries
#include "bullet.h"
#include "boxset.h"
#include "room.h"

// Standard namespaces
using namespace std;

class Weapon
{
      public:
             
             // weapon position
             point position;
             
             //collection of bullets
             Bullet *bullets;
             
             //capacity of magazine
             const int bulletsNum;
             
             //number of bullet to be launched
             int currentBullet;
             
             //direction of weapon
             point direction;
             
             // Set of boxes
             BoxSet* boxset;
             
             // Reference to room
             Room* room;
             
             Weapon(point position, int bulletsNum, BoxSet* boxset, Room* room):bulletsNum(bulletsNum)
             {
                   this->position = position;
                   
                   this->boxset = boxset;
                   
                   this->room = room;
                     
                   this->bullets = new Bullet[bulletsNum];
                      
                   int i;
                   for(i = 0; i < bulletsNum; i++)
                   {
                      this->bullets[i] = Bullet( position );
                   }
                   this->currentBullet = 0;
             }
      
             void ChangeDirection(float x, float y){                  
                  direction.SetX(x);
                  direction.SetY(y);
                  direction.SetZ( - 12.0 );
                  
                  direction.normalize();
                  
             }
             
             void DrawViewFinder()
             {
                  glColor3f(1, 0, 0);
                  
                  // vertical rotation axis of view finder
                  float verticalZ;
                  
                  glPushMatrix();
                      
                      glTranslatef(0.0, 0.0, this->position.GetZ());
                      glRotatef( atan( direction.GetX() / direction.GetZ()) * 180 / M_PI, 0, 1, 0);
                      verticalZ = - sqrt( direction.GetX() * direction.GetX() + direction.GetZ() * direction.GetZ() );
                      glRotatef( atan( direction.GetY() / verticalZ) * 180.0 / M_PI, -0.1, 0.0, 0.0);
                      glTranslatef(0.0, 0.0, -3);
                      
                      // Horizontal line
                      glBegin(GL_QUADS);
                                  glNormal3f(0,0,-1);
                                  glVertex3f (- 0.2, 0.008, 0);
                                  glVertex3f (0.2, 0.008, 0);
                                  glVertex3f (0.2, -0.008, 0);
                                  glVertex3f (- 0.2, -0.008, 0);           
                      glEnd();
                      
                      // Vertical line
                      glBegin(GL_QUADS);
                                  glNormal3f(0,0,-1);
                                  glVertex3f ( - 0.008, 0.2, 0);
                                  glVertex3f (0.008, 0.2, 0);
                                  glVertex3f (0.008, -0.2, 0);
                                  glVertex3f ( - 0.008,  -0.2, 0);           
                      glEnd();
                      
                  glPopMatrix();
                  
             }
             
             void DrawBullets()
             {
                  int i;
                  for( i = 0; i < this->bulletsNum; i++ )
                  {
                     boxset->CheckBoxesForHit(&bullets[i]);
                     
                     room->CheckIfHit(&bullets[i]);
                     
                     this->bullets[i].Draw();         
                  }
                  glLoadIdentity();
             }
             
             void Shot()
             {
                if( currentBullet < bulletsNum )
                {
                  bullets[currentBullet].GiveMomentum(direction);
                  currentBullet++;
                }    
             }
             
             int GetLastBulletsNum()
             {
                 return bulletsNum - currentBullet;
             }
};
