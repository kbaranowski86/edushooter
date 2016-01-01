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

      ThreeLevelBox(point, point, char*);
      void Draw();
      bool CheckIfHit(Bullet*);
      void SetHit( bool );
      void MoveAlongY(double);
};
