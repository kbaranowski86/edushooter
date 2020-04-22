#include <iostream>
#include "AnswerBox.h"
#include "BoxSet.h"
#include <array>
#ifndef ANSWERBOXSET_H
#define ANSWERBOXSET_H

class AnswerBoxSet : public BoxSet
{
    public:
        std::array<shared_ptr<AnswerBox>, 3> shuffledBoxes;
        char correctAnswerIndex;
        bool correctAnswerHit;
        int correctAnswerPointsNum;

        AnswerBoxSet(const double&, const double&, const double&, const double&);

        void AnimateShuffledBoxes();
        // Move shuffled box up and down
        void MoveShuffled(double, double);
        void Shuffle();
        void ShuffleAnswerIndexes();
        void CheckBoxesForHit(Bullet&);
};
#endif // ANSWERBOXSET_H
