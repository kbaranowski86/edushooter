// Project libraries
#include "threelevelboxset.h"
#include "answerboxset.h"
#ifndef BOXSETSET_H
#define BOXSETSET_H

class BoxSetSet
{

    public:
        BoxSet* boxSets[3];

        int currentSetNum;
        bool currentSetHit;

        BoxSetSet();

        void Animate();

};
#endif // BOXSETSET_H
