#include "boxset.h"

BoxSet::BoxSet(const double& spacing, const double& verticalPosition, const double& depth, const double& moveSpeedMultiplier ) {
    this->verticalPosition = verticalPosition;

    this->moveSpeedMultiplier = moveSpeedMultiplier;
    cycleEnd = 0;

    //rows, cols
    int i, j;
    for(i = 0; i < 3; i++)
    {
         for( j = 0.0; j < 8 ; j++ )
         {
            boxes[ i ][ j ] = make_shared<Box>(
                        Point( 4.7 - j - spacing * j - 1.0, verticalPosition, i * 3 ),
                        Point( 4.7 - j - spacing * j, verticalPosition - 1.3, i * 3 + depth),
                        Point(0.7, 0.7, 0.7),
                        2, "img\\gres.bmp" );
         }
    }

    Shuffle();
}

void BoxSet::AnimateShuffledBoxes() {
    shuffledBox->Draw();
    MoveShuffled(0.02 * moveSpeedMultiplier, moveSpeedMultiplier);
}

void BoxSet::Shuffle() {
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

bool BoxSet::IsCycleEnd() {
    return this->cycleEnd;
}

void BoxSet::MoveShuffled(const double& moveDownSpeed, const double& moveUpSpeed) {
    if(shuffledBox->upperLeftBack.GetY() > 0)
    {
       shuffledBox->moveDirection = - moveDownSpeed;
    }
    else if(shuffledBox->upperLeftBack.GetY() < -1.0)
    {
       cycleEnd = true;

       shuffledBox->moveDirection = shuffledBox->initialMoveDirection;

       shuffledBox->MoveTo( Point( shuffledBox->upperLeftBack.GetX(), this->verticalPosition, shuffledBox->upperLeftBack.GetZ() ), 0 );

       Shuffle();

       return;
    }
    shuffledBox->MoveAlongY(shuffledBox->moveDirection);
}

void BoxSet::CheckBoxesForHit(Bullet& hittingBullet) {
    if( shuffledBox->CheckIfHit( hittingBullet ) )
    {
        Score::GetInstance().IncreasePointsOf( shuffledBox->pointsNum );
    }
}
