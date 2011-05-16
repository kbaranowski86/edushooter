class Room : public Box
{

      public:
          Room(point upperLeftBack = point(0,0,0), point lowerRightFront=point(0,0,0), float r = 0, float g = 0, float b = 0, char* texturePath = "") : Box(upperLeftBack, lowerRightFront, r, g, b, 0, texturePath)
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
                       glTexCoord2d(0, 1); glVertex3f (this->upperLeftBack.GetX(), this->upperLeftBack.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->lowerRightFront.GetX(), this->upperLeftBack.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->lowerRightFront.GetX(), this->lowerRightFront.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->upperLeftBack.GetX(), this->lowerRightFront.GetY(), this->lowerRightFront.GetZ());

            glEnd();

            // front wall
            glBegin(GL_QUADS);
                       glNormal3f(0, 0, -1);
                       glTexCoord2d(0, 1); glVertex3f (this->upperLeftBack.GetX(), this->upperLeftBack.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->lowerRightFront.GetX(), this->upperLeftBack.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->lowerRightFront.GetX(), this->lowerRightFront.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->upperLeftBack.GetX(), this->lowerRightFront.GetY(), this->upperLeftBack.GetZ());

            glEnd();

            // left wall
            glBegin(GL_QUADS);
                       glNormal3f(1, 0, 0);
                       glTexCoord2d(0, 1); glVertex3f (this->upperLeftBack.GetX(), this->upperLeftBack.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->upperLeftBack.GetX(), this->upperLeftBack.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->upperLeftBack.GetX(), this->lowerRightFront.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->upperLeftBack.GetX(), this->lowerRightFront.GetY(), this->upperLeftBack.GetZ());

            glEnd();

            // right wall
            glBegin(GL_QUADS);
                       glNormal3f(-1, 0, 0);
                       glTexCoord2d(0, 1); glVertex3f (this->lowerRightFront.GetX(), this->upperLeftBack.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->lowerRightFront.GetX(), this->upperLeftBack.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->lowerRightFront.GetX(), this->lowerRightFront.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->lowerRightFront.GetX(), this->lowerRightFront.GetY(), this->upperLeftBack.GetZ());

            glEnd();

            // top wall
            glBegin(GL_QUADS);
                       glNormal3f(0,1,0);
                       glTexCoord2d(0, 1); glVertex3f (this->upperLeftBack.GetX(), this->upperLeftBack.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->lowerRightFront.GetX(), this->upperLeftBack.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->lowerRightFront.GetX(), this->upperLeftBack.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->upperLeftBack.GetX(), this->upperLeftBack.GetY(), this->upperLeftBack.GetZ());

            glEnd();

            // bottom wall
            glBegin(GL_QUADS);
                       glNormal3f(0,-1,0);
                       glTexCoord2d(0, 1); glVertex3f (this->upperLeftBack.GetX(), this->lowerRightFront.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 1); glVertex3f (this->lowerRightFront.GetX(), this->lowerRightFront.GetY(), this->lowerRightFront.GetZ());
                       glTexCoord2d(1, 0); glVertex3f (this->lowerRightFront.GetX(), this->lowerRightFront.GetY(), this->upperLeftBack.GetZ());
                       glTexCoord2d(0, 0); glVertex3f (this->upperLeftBack.GetX(), this->lowerRightFront.GetY(), this->upperLeftBack.GetZ());

            glEnd();

        }

          bool CheckIfHit(Bullet* hittingBullet)
          {
                 if( (hittingBullet->GetPosition().GetX() <= upperLeftBack.GetX() || hittingBullet->GetPosition().GetX() >= lowerRightFront.GetX())
                 || (hittingBullet->GetPosition().GetY() >= upperLeftBack.GetY() || hittingBullet->GetPosition().GetY() <= lowerRightFront.GetY())
                 || (hittingBullet->GetPosition().GetZ() <= upperLeftBack.GetZ() || hittingBullet->GetPosition().GetZ() >= lowerRightFront.GetZ() )
                 )
                 {
                     hittingBullet->GiveMomentum(point(0, 0, 0));
                     return true;
                 }
                 return false;
          }
};
