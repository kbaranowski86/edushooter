#include "threelevelboxset.h"

ThreeLevelBoxSet::ThreeLevelBoxSet( double spacing, double verticalPosition, double depth, double moveSpeedMultiplier ):
    BoxSet( spacing, verticalPosition, depth, moveSpeedMultiplier )
    {
        int i, j;
        for(i = 0; i < 3; i++)
        {
             for( j = 0; j < 8 ; j++ )
             {
                boxes[i][j] = std::make_shared<ThreeLevelBox>(
                            Point( 4.7 - j - spacing * j - 1, verticalPosition, i * 3 ),
                            Point( 4.7 - j - spacing * j, -1.3 + verticalPosition, i * 3 + depth), "img\\cegla.bmp");
             }
        }
        Shuffle();
    }
