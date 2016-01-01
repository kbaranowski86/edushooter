// Project libraries
#include "box.h"
#ifndef ANSWERBOX_H
#define ANSWERBOX_H

class AnswerBox : public Box
{
    private:
        int answerIndex;
        std::string texturePath;

    public:
        AnswerBox( point, point, point, double, char* );
        void SetAnswerIndex( int );
        int GetAnswerIndex();
        void Draw();
};
#endif // ANSWERBOX_H
