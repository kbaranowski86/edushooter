class Room : public Box
{
      public:   
          Room(point P1 = point(0,0,0), point P2=point(0,0,0), float r = 0, float g = 0, float b = 0, char* texturePath = "") : Box(P1, P2, r, g, b, texturePath)
          {
                    
          }
      
          void Draw(){
             
            glPolygonMode(GL_FRONT, GL_FILL);
            glPolygonMode(GL_BACK, GL_FILL);
            
            if(!hit)
            {
                glColor3f(r, g, b);
            }
            else
            {
                glColor3f(hitR, hitG, hitB);
            }   
            
            // back wall
            glBegin(GL_QUADS);
                       glNormal3f(0, 0, 1);
                       glTexCoord2d(0, 1); glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P2.GetZ());
                       
            glEnd();
            
            // front wall
            glBegin(GL_QUADS);
                       glNormal3f(0, 0, -1);
                       glTexCoord2d(0, 1); glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P1.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // left wall
            glBegin(GL_QUADS);
                       glNormal3f(1, 0, 0);
                       glTexCoord2d(0, 1); glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // right wall
            glBegin(GL_QUADS);
                       glNormal3f(-1, 0, 0);
                       glTexCoord2d(0, 1); glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // top wall
            glBegin(GL_QUADS);
                       glNormal3f(0,1,0);
                       glTexCoord2d(0, 1); glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // bottom wall
            glBegin(GL_QUADS);
                       glNormal3f(0,-1,0);
                       glTexCoord2d(0, 1); glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P1.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
        }
      
          bool CheckIfHit(Bullet* hittingBullet)
          {             
                 if( (hittingBullet->GetPosition().GetX() <= P1.GetX() || hittingBullet->GetPosition().GetX() >= P2.GetX())
                 || (hittingBullet->GetPosition().GetY() >= P1.GetY() || hittingBullet->GetPosition().GetY() <= P2.GetY())
                 || (hittingBullet->GetPosition().GetZ() <= P1.GetZ() || hittingBullet->GetPosition().GetZ() >= P2.GetZ() )
                 )
                 {
                     hittingBullet->GiveMomentum(point(0, 0, 0));
                     return true;
                 }
                 return false;
          }
};
