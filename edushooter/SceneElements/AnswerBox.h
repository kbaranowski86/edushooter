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
        AnswerBox(const Point&, const Point&, const Point&, const double&, const std::string& );
        void SetAnswerIndex(const int&);
        int GetAnswerIndex() const;
        void Draw();
};
#endif // ANSWERBOX_H
