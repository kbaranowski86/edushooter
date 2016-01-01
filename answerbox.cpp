#include "answerbox.h"

AnswerBox::AnswerBox(point upperLeftBack, point lowerRightFront, point color, double pointsNum, char* texturePath = ""):
    Box( upperLeftBack, lowerRightFront, color, pointsNum, texturePath ) {
        answerIndex = 0;
    }

void AnswerBox::SetAnswerIndex(int answerIndex) {
    this->answerIndex = answerIndex;
}

int AnswerBox::GetAnswerIndex() {
    return this->answerIndex;
}

void AnswerBox::Draw() {
    Box::Draw();

    char answerIndexString[100];
    sprintf( answerIndexString, "%i", answerIndex );

    Utils::PutTextStable( point( lowerRightFront.GetX() - 0.5 * width, upperLeftBack.GetY() - 0.5 * height, lowerRightFront.GetZ() + 0.03 ) , point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, answerIndexString);
}
