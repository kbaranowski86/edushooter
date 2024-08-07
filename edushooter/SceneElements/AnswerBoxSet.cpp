#include "answerboxset.h"

AnswerBoxSet::AnswerBoxSet(const double& spacing, const double& verticalPosition, const double& depth, const double& moveSpeedMultiplier ):
BoxSet( spacing, verticalPosition, depth, moveSpeedMultiplier )
{
    correctAnswerPointsNum = 8;

    correctAnswerHit = false;

    //rows, cols
    int i, j;
    for(i = 0; i < 3; i++)
    {
         for( j = 0.0; j < 8 ; j++ )
         {
            boxes[ i ][ j ] = std::make_shared<AnswerBox>(
                        Point( 4.7 - j - spacing * j - 1.0, verticalPosition, i * 3 ),
                        Point( 4.7 - j - spacing * j, verticalPosition - 1.3, i * 3 + depth),
                        Point( 0.7, 0.7, 0.7 ),
                        2, "img\\marmur.bmp" );
         }
    }

    correctAnswerIndex = 1;

    Shuffle();
    ShuffleAnswerIndexes();
}

void AnswerBoxSet::AnimateShuffledBoxes()
{
    int i;
    for( i = 0; i < 3; i++ )
    {
        shuffledBoxes[ i ]->Draw();
    }

    InfoBar::GetInstance().DrawBonusInfo( correctAnswerIndex );

    MoveShuffled(0.015 * moveSpeedMultiplier, moveSpeedMultiplier);
}

// Move shuffled box up and down
void AnswerBoxSet::MoveShuffled(double moveDownSpeed, double moveUpSpeed)
{

    int boxesDown = 0;

    int i;
    for( i = 0; i < 3; i++ )
    {
        if( shuffledBoxes[ i ]->upperLeftBack.GetY() > 0 )
        {
            shuffledBoxes[ i ]->moveDirection = - moveDownSpeed;
        }
        else if(shuffledBoxes[ i ]->upperLeftBack.GetY() < this->verticalPosition )
        {

            shuffledBoxes[i]->MoveTo( Point( shuffledBoxes[i]->upperLeftBack.GetX(), this->verticalPosition, shuffledBoxes[i]->upperLeftBack.GetZ() ), 0 );

            boxesDown ++;

        }

    }

    if( boxesDown == 3 )
    {
        for( i = 0; i < 3; i++ )
        {
            shuffledBoxes[ i ]->moveDirection = shuffledBoxes[i]->initialMoveDirection;
        }

        Shuffle();

        ShuffleAnswerIndexes();

        cycleEnd = true;

        return;
    }
    for( i = 0; i < 3; i++ )
    {
        shuffledBoxes[ i ]->MoveAlongY( shuffledBoxes[ i ]->moveDirection );
    }
}

void AnswerBoxSet::Shuffle()
{
    int s[2];
    int i = 0;
    int j;

    int tmpCol[3];
    bool columnFree = true;

    while( i < 3 )
    {

        s[0] = (rand() % 230) / 80;
        s[1] = (rand() % 230) / 30;

        // check if previous cols are engaged
        if( i > 0 )
        {
            for( j = 0; j < i; j++ )
            {
                if( s[1] == tmpCol[ j ] )
                {
                    columnFree = false;
                    break;
                }
                else
                {
                    columnFree = true;
                }
            }
        }

        if( columnFree == true )
        {
            this->shuffledBoxes[ i ] = dynamic_pointer_cast<AnswerBox>(boxes[ s[0] ][ s[1] ]);
            tmpCol[ i ] = s[1];
            i++;
        }

    }

    // Unhit shuffled box if hit
    for( i = 0; i < 3; i++ )
    {
        if(shuffledBoxes[ i ]->GetHit())
        {
            shuffledBoxes[ i ]->SetHit( false );
        }
    }
}

void AnswerBoxSet::ShuffleAnswerIndexes()
{
    int tmpIndex;
    int i = 0;
    int j = 0;
    bool indexFree = true;

    //shuffle correct answer index
    correctAnswerIndex = rand() % 3;
    correctAnswerHit = false;

    while( i < 3 )
    {
        tmpIndex = rand() % 3;

        if( i > 0 )
        {
            for(j = 0; j < i; j++ )
            {
                if( tmpIndex == shuffledBoxes[j]->GetAnswerIndex() )
                {
                    indexFree = false;
                    break;
                }
                else
                {
                    indexFree = true;
                }
            }
        }

        if( indexFree == true )
        {
            shuffledBoxes[j]->SetAnswerIndex( tmpIndex );
            i++;
        }
    }
}

void AnswerBoxSet::CheckBoxesForHit(Bullet& hittingBullet)
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        // check if there is any hit
        if( shuffledBoxes[i]->CheckIfHit( hittingBullet ) )
        {
            // check if correct box hit
            if( shuffledBoxes[i]->GetAnswerIndex() == correctAnswerIndex )
            {
                Score::GetInstance().IncreasePointsOf( correctAnswerPointsNum );
                correctAnswerHit = true;
            }
            else if( shuffledBoxes[i]->GetAnswerIndex() != correctAnswerIndex && correctAnswerHit == false )
            {
                Score::GetInstance().IncreasePointsOf( shuffledBoxes[i]->pointsNum );
                for( j = 0; j < 3; j++ )
                {
                    shuffledBoxes[j]->moveDirection = -0.1;
                }
            }
        }
    }
}
