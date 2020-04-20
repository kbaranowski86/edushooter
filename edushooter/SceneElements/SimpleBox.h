//3rd party libraries
#include "BMPLoader.h"

//Project libraries
#include "box.h"

class Score;

//definicja prostopadloscianu
class SimpleBox : public Box
{
      public:
        // walls
        Rect backWall;
        Rect frontWall;
        Rect leftWall;
        Rect rightWall;
        Rect topWall;
        Rect bottomWall;
        
        float r;
        float g;
        float b;
        float hitR;
        float hitG;
        float hitB;
        BMPClass textureImage;
        Score* scr;
        
        SimpleBox(){}
        
        SimpleBox(Point upperLeftBack = Point(0,0,0), Point lowerRightFront = Point(0,0,0), float r = 0, float g = 0, float b = 0, Score* scr, float momentum):
            backWall( upperLeftBack, Point(lowerRightFront.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ()), Point(0, 0, -1) ),
            frontWall( Point(upperLeftBack.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ()), lowerRightFront, Point(0, 0, 1) ),
            leftWall( upperLeftBack, Point(upperLeftBack.GetX(), lowerRightFront.GetY(), lowerRightFront.GetZ()), Point(-1, 0, 0), Utils::ZY ),
            rightWall( Point( lowerRightFront.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), lowerRightFront, Point(1, 0, 0), Utils::ZY ),
            topWall( upperLeftBack, Point( lowerRightFront.GetX(), upperLeftBack.GetY(), lowerRightFront.GetZ() ), Point(0, 1, 0), Utils::XZ ),
            bottomWall( Point( upperLeftBack.GetX(), lowerRightFront.GetY(), upperLeftBack.GetZ() ), lowerRightFront, Point(0, -1, 0), Utils::XZ )
        {
                
                this->r = r;
                this->g = g;
                this->b = b;
                this->hitR = 0.8;
                this->hitG = 0.8;
                this->hitB = 0.8;
                
                hit = false;
                
                this->scr = scr;
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
            
            backWall.Draw();
            frontWall.Draw();
            leftWall. Draw();
            rightWall.Draw();
            topWall.Draw();
            bottomWall.Draw();
        }
        
        void MoveBy(Point p){
             backWall.MoveBy(p);
             frontWall.MoveBy(p);
             leftWall.MoveBy(p);
             rightWall.MoveBy(p);      
             topWall.MoveBy(p);
             bottomWall.MoveBy(p);         
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
        
        void SetColor(Point vector)
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
             if( ( hittingBullet->GetPosition().GetX() >= frontWall.GetUpperLeft()->GetX() && hittingBullet->GetPosition().GetX() <= frontWall.GetLowerRight()->GetX() )
             && ( hittingBullet->GetPosition().GetY() <= frontWall.GetUpperLeft()->GetY() && hittingBullet->GetPosition().GetY() >= frontWall.GetLowerRight()->GetY() )
             && ( hittingBullet->GetPosition().GetZ() >= frontWall.GetUpperLeft()->GetZ() && hittingBullet->GetPosition().GetZ() <= frontWall.GetLowerRight()->GetZ() )
             && hittingBullet->GetMomentum() != Point(0.0, 0.0, 0.0)
             )
             {
                                                     
                 if(!CheckIfHit())
                 {
                      this->hit = true;
                 }
                 
                 hittingBullet->GiveMomentum(Point(0, 0, 0));
                 
                 return true;
             }
             return false;
        }
};
