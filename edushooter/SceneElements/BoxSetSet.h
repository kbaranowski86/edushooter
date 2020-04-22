// Project libraries
#include "ThreeLevelBoxSet.h"
#include "AnswerBoxSet.h"
#ifndef BOXSETSET_H
#define BOXSETSET_H

class BoxSetSet
{

    public:
        std::array<unique_ptr<BoxSet>, 3> boxSets;

        int currentSetNum;
        bool currentSetHit;

        BoxSetSet();

        void Animate();

};
#endif // BOXSETSET_H
