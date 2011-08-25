#include <time.h>
#include <stdlib.h>

//Project libraries
#include "box.h"

// zestaw klocków
class BoxSet
{
    public:

    Box* boxes[3][8];
    Box* shuffledBox;
    bool cycleEnd;
    double moveSpeedMultiplier;
    double verticalPosition;

    // Locating boxes on the scene
    BoxSet( double spacing, double verticalPosition, double depth, double moveSpeedMultiplier )
    {

        this->verticalPosition = verticalPosition;

        this->moveSpeedMultiplier = moveSpeedMultiplier;
        cycleEnd = 0;

        //rows, cols
        int i, j;
        for(i = 0; i < 3; i++)
        {
             for( j = 0.0; j < 8 ; j++ )
             {
                boxes[ i ][ j ] = new Box(
                            point( 4.7 - j - spacing * j - 1.0, verticalPosition, i * 3 ),
                            point( 4.7 - j - spacing * j, verticalPosition - 1.3, i * 3 + depth),
                            0.7,
                            0.7,
                            0.7,
                            2, "gres.bmp" );
             }
        }

        Shuffle();
    }

    virtual void AnimateShuffledBoxes()
    {
        shuffledBox->Draw();

        MoveShuffled(0.08 * moveSpeedMultiplier, 1 * moveSpeedMultiplier);
    }

    virtual void Shuffle()
    {
        int s[2];

        s[0] = (rand() % 230) / 80;
        s[1] = (rand() % 230) / 30;

        this->shuffledBox = boxes[s[0]][s[1]];

        // Unhit shuffled box if hit
        if(shuffledBox->GetHit())
        {
            shuffledBox->SetHit( false );
        }

    }

    bool IsCycleEnd()
    {
        return this->cycleEnd;
    }

    // Move shuffled box up and down
    virtual void MoveShuffled(double moveDownSpeed, double moveUpSpeed)
    {

        if(shuffledBox->upperLeftBack.GetY() > 0)
        {
           shuffledBox->moveDirection = - moveDownSpeed;
        }
        else if(shuffledBox->upperLeftBack.GetY() < -1.0)
        {
           cycleEnd = true;

           shuffledBox->moveDirection = shuffledBox->initialMoveDirection;

           shuffledBox->MoveTo( point( shuffledBox->upperLeftBack.GetX(), this->verticalPosition, shuffledBox->upperLeftBack.GetZ() ), 0 );

           Shuffle();

           return;
        }
        shuffledBox->MoveAlongY(shuffledBox->moveDirection);


    }

    virtual void CheckBoxesForHit(Bullet* hittingBullet)
    {
        if( shuffledBox->CheckIfHit( hittingBullet ) )
        {
            Score::GetInstance().IncreasePointsOf( shuffledBox->pointsNum );
        }
    }
};
