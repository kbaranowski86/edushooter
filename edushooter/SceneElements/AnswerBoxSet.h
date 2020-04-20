#include <iostream>
#include "AnswerBox.h"
#include "BoxSet.h"
#ifndef ANSWERBOXSET_H
#define ANSWERBOXSET_H

class AnswerBoxSet : public BoxSet
{
    public:
        AnswerBox* shuffledBoxes[3];
        char correctAnswerIndex;
        bool correctAnswerHit;
        int correctAnswerPointsNum;

        AnswerBoxSet( double, double, double, double );

        void AnimateShuffledBoxes();
        // Move shuffled box up and down
        void MoveShuffled(double, double);
        void Shuffle();
        void ShuffleAnswerIndexes();
        void CheckBoxesForHit(Bullet*);
};
#endif // ANSWERBOXSET_H
