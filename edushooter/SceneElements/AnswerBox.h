// Project libraries
#include "..\BasicShapes\Box.h"
#ifndef ANSWERBOX_H
#define ANSWERBOX_H

class AnswerBox : public Box
{
    private:
        int answerIndex;
        std::string texturePath;

    public:
        AnswerBox( Point, Point, Point, double, const char* );
        void SetAnswerIndex( int );
        int GetAnswerIndex();
        void Draw();
};
#endif // ANSWERBOX_H
