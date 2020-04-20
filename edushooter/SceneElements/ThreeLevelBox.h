// Built-in libraries
#include <cmath>

// Project libraries
#include "..\BasicShapes\Box.h"

class ThreeLevelBox : public Box
{
   private:

      // height of piece of front wall
      double levelHeight;

      Box firstPiece;
      Box secondPiece;
      Box thirdPiece;

   public:

      ThreeLevelBox(Point, Point, const char*);
      void Draw();
      bool CheckIfHit(Bullet*);
      void SetHit( bool );
      void MoveAlongY(double);
};
