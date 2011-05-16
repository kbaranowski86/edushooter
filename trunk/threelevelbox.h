// Built-in libraries
#include <cmath>

// Project libraries
#include "box.h"

class ThreeLevelBox : public Box
{
   private:

      // height of piece of front wall
      double levelHeight;

      Box firstPiece;
      Box secondPiece;
      Box thirdPiece;

   public:

      ThreeLevelBox(point upperLeftBack, point lowerRightFront):
      Box( upperLeftBack, lowerRightFront, 0, 0, 0, 0.0f ),
      levelHeight( std::fabs( upperLeftBack.GetY() - lowerRightFront.GetY() ) / 3),
      firstPiece( point( upperLeftBack.GetX(), upperLeftBack.GetY(), upperLeftBack.GetZ() ), point( lowerRightFront.GetX(), upperLeftBack.GetY() - levelHeight, lowerRightFront.GetZ() ), 1, 0, 0, 2.0f ),
      secondPiece( point( upperLeftBack.GetX(), upperLeftBack.GetY() - levelHeight, upperLeftBack.GetZ()  ), point( lowerRightFront.GetX(), upperLeftBack.GetY() - 2 * levelHeight, lowerRightFront.GetZ() ),  0, 1, 0, 4.0f ),
      thirdPiece( point( upperLeftBack.GetX(), upperLeftBack.GetY() - 2 * levelHeight, upperLeftBack.GetZ()  ), lowerRightFront,  0, 0, 1, 8.0f )
      {
      }

      void Draw()
      {
           firstPiece.Draw();

           secondPiece.Draw();

           thirdPiece.Draw();
      }

      bool CheckIfHit(Bullet* hittingBullet)
      {
         if( firstPiece.CheckIfHit(hittingBullet) )
         {
             Score::GetInstance().IncreasePointsOf( 1 );
             moveDirection = -0.1;

             Box::SetHit( true );
             return true;
         }
         else if( secondPiece.CheckIfHit( hittingBullet ) )
         {
             Score::GetInstance().IncreasePointsOf( 2 );

             moveDirection = -0.1;

             Box::SetHit( true );
             return true;
         }
         else if( thirdPiece.CheckIfHit( hittingBullet ) )
         {
             Score::GetInstance().IncreasePointsOf( 3 );

             moveDirection = -0.1;

             Box::SetHit( true );
             return true;
         }

         return false;
      }

      void SetHit( bool hit )
      {
           firstPiece.SetHit( hit );
           secondPiece.SetHit( hit );
           thirdPiece.SetHit( hit );

           Box::SetHit( hit );
      }

      void MoveAlongY(double y)
      {
           firstPiece.MoveAlongY(y);
           secondPiece.MoveAlongY(y);
           thirdPiece.MoveAlongY(y);

           this->MoveBy(point(0, y, 0));
      }
};
