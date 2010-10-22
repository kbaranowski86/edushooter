//3rd party libraries
#include "BMPLoader.h"

//definicja prostopadloscianu
class Box
{
      public:
        point P1;
        point P2;
        float r;
        float g;
        float b;
        float hitR;
        float hitG;
        float hitB;
        float moveDirection;
        bool hit;
        BMPClass textureImage;
        
        Box(point P1 = point(0,0,0), point P2=point(0,0,0), float r=0, float g=0, float b=0, char* texturePath = ""){
                
                // setting texture
                if(texturePath != "")
                {
                    BMPLoad(texturePath, textureImage);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexImage2D(GL_TEXTURE_2D, 0, 3, textureImage.width, textureImage.height, 0, GL_RGB,GL_UNSIGNED_BYTE, textureImage.bytes);
                }
                
                
                this->moveDirection = 0.3;
                
                //top left back point
                this->P1 = P1;
                
                // bottom right front point
                this->P2 = P2;
                
                this->r = r;
                this->g = g;
                this->b = b;
                this->hitR = 0.8;
                this->hitG = 0.8;
                this->hitB = 0.8;
                
                hit = false;
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
                       glNormal3f(0,0,-1);
                       glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P2.GetZ());
                       
            glEnd();
            
            // front wall
            glBegin(GL_QUADS);
                       glNormal3f(0,0,1);
                       glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P1.GetZ());
                       glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // left wall
            glBegin(GL_QUADS);
                       glNormal3f(-1,0,0);
                       glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // right wall
            glBegin(GL_QUADS);
                       glNormal3f(1,0,0);
                       glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // top wall
            glBegin(GL_QUADS);
                       glNormal3f(0,1,0);
                       glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P1.GetY(), this->P1.GetZ());
                       glVertex3f (this->P1.GetX(), this->P1.GetY(), this->P1.GetZ());
                       
            glEnd();
            
            // bottom wall
            glBegin(GL_QUADS);
                       glNormal3f(0,-1,0);
                       glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P2.GetZ());
                       glVertex3f (this->P2.GetX(), this->P2.GetY(), this->P1.GetZ());
                       glVertex3f (this->P1.GetX(), this->P2.GetY(), this->P1.GetZ());
                       
            glEnd();
            
        }
        
        void MoveBy(point P){
             this->P1 = this->P1 + P;
             this->P2 = this->P2 + P;
        }
        
        void MoveAlongX(float x){
             this->MoveBy(point(x, 0, 0));
        }
        
        void MoveAlongY(float y){
             this->MoveBy(point(0, y, 0));
        }
        
        void MoveAlongZ(float z){
             this->MoveBy(point(0, 0, z));
        }
        
        void UnHit()
        {
             this->hit = false;
        }
        
        void SetColor(float r, float g, float b)
        {
             this->r = r;
             this->g = g;
             this->b = b;
        }
        
        void SetColor(point vector)
        {
             r = vector.GetX();
             g = vector.GetY();
             b = vector.GetZ();
        }
        
        bool CheckIfHit()
        {
             return hit;
        }
        
        bool CheckIfHit(Bullet* hittingBullet)
        {             
             if( ( hittingBullet->GetPosition().GetX() >= P1.GetX() && hittingBullet->GetPosition().GetX() <= P2.GetX() )
             && ( hittingBullet->GetPosition().GetY() <= P1.GetY() && hittingBullet->GetPosition().GetY() >= P2.GetY() )
             && ( hittingBullet->GetPosition().GetZ() >= P1.GetZ() && hittingBullet->GetPosition().GetZ() <= P2.GetZ() )
             && hittingBullet->GetMomentum() != point(0.0, 0.0, 0.0)
             )
             {
                                                     
                 if(!CheckIfHit())
                 {
                      this->hit = true;
                 }
                 
                 hittingBullet->GiveMomentum(point(0, 0, 0));
                 
                 return true;
             }
             return false;
        }
};
