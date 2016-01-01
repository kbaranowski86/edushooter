#include "boxsetset.h"

BoxSetSet::BoxSetSet() {
    currentSetHit = false;

    currentSetNum = 0;

    boxSets[0] = new ThreeLevelBoxSet( 0.2, -1.0, 0.8, 0.1 );
    boxSets[1] = new BoxSet( 0.2, -1.0, 0.8, 0.1 );
    boxSets[2] = new AnswerBoxSet( 0.2, -1.0, 0.8, 0.1 );
}

void BoxSetSet::Animate() {
    boxSets[currentSetNum]->AnimateShuffledBoxes();
            // check if up-down cycle of box/boxes end
    if(boxSets[currentSetNum]->cycleEnd == true )
    {
        if( currentSetNum == 0 )
        {
            currentSetNum ++;
        }
        else if( currentSetNum == 1 && currentSetHit == true )
        {
            currentSetNum ++;
            currentSetHit = false;
        }
        else if( currentSetNum == 2 )
        {
            currentSetNum = 0;
        }

        //reset cycle state
        boxSets[currentSetNum]->cycleEnd = false;
    }
    else
    {
        if( currentSetNum == 1 )
        {
            // check if current boxset hit
            if( boxSets[currentSetNum]->shuffledBox->GetHit() )
            {
                currentSetHit = true;
            }
        }
    }
}
