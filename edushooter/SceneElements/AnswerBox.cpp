#include "AnswerBox.h"

AnswerBox::AnswerBox(const Point& upperLeftBack, const Point& lowerRightFront, const Point& color, const double& PointsNum, const std::string& texturePath = ""):
    Box( upperLeftBack, lowerRightFront, color, pointsNum, texturePath ) {
        answerIndex = 0;
    }

void AnswerBox::SetAnswerIndex(const int& answerIndex) {
    this->answerIndex = answerIndex;
}

int AnswerBox::GetAnswerIndex() const {
    return this->answerIndex;
}

void AnswerBox::Draw() {
    Box::Draw();

    char answerIndexString[100];
    sprintf_s( answerIndexString, "%i", answerIndex );

    Utils::Text::PutTextStable( Point( lowerRightFront.GetX() - 0.5 * width, upperLeftBack.GetY() - 0.5 * height, lowerRightFront.GetZ() + 0.03 ) , Point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, answerIndexString);
}
