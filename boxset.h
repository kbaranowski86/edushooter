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
    BoxSet( double, double, double, double );

    virtual void AnimateShuffledBoxes();

    virtual void Shuffle();

    bool IsCycleEnd();

    // Move shuffled box up and down
    virtual void MoveShuffled(double, double);

    virtual void CheckBoxesForHit(Bullet*);
};
