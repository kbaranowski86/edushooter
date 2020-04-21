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

      ThreeLevelBox(const Point&, const Point&, const std::string&);
      void Draw();
      bool CheckIfHit(Bullet&);
      void SetHit(const bool&);
      void MoveAlongY(const double&);
};
