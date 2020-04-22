#include <time.h>
#include <stdlib.h>
#include <array>

//Project libraries
#include "..\BasicShapes\Box.h"
#ifndef BOXSET_H
#define BOXSET_H

// zestaw klocków
class BoxSet
{
    public:
        std::array<std::array<shared_ptr<Box>, 8>, 3> boxes;
        shared_ptr<Box> shuffledBox;
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

        virtual void CheckBoxesForHit(Bullet&);
};
#endif // BOXSET_H
