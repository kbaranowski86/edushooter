#include "InfoBar.h"

InfoBar::InfoBar() {
    hitTime = 0;
    position = Point( 0, 0, 0);
    barBg = Rect( Point( 0.15, 0.29, position.GetZ() -0.51 ) , Point( 0.3, 0.215, position.GetZ() -0.51 ), Point( 0, 0, -1 ), Point( 1, 1, 1), Utils::Geometry::Orientation::XY, std::string(), true, false );
}

void InfoBar::SetPoints(int points) {
    this->points = points;
}

void InfoBar::SetPlayTime(double playTime) {
    this->playTime = playTime;
}

void InfoBar::SetBullets(int bullets)
{
    this->bullets = bullets;
}

void InfoBar::SetHitIndicating()
{
    time( &hitTime );
}

bool InfoBar::CheckHitIndicating()
{
    time( &actualTime );

    hitIndicatingLastTime = difftime( actualTime, hitTime );

    if( hitIndicatingLastTime <= 1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InfoBar::SetAll(int points, double playTime, int bullets)
{
    this->points = points;
    this->playTime = playTime;
    this->bullets = bullets;
}

void InfoBar::DrawBonusInfo( int correctAnswerIndex )
{
    const char* caption = "Numer klocka z bonusem: ";
    char correctAnswerIndexString[100];

    sprintf_s( correctAnswerIndexString, "%i", correctAnswerIndex );

    Utils::Text::PutTextCamFollowing(Point(position.GetX() - 0.1, position.GetY() + 0.22, position.GetZ() - 0.5), Point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, caption);
    Utils::Text::PutTextCamFollowing(Point(position.GetX() + 0.1, position.GetY() + 0.22, position.GetZ() - 0.5), Point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, correctAnswerIndexString);
}

void InfoBar::Draw()
{
    char pointsString[100];
    char playTimeString[100];
    char bulletsString[100];

    hitIndicatingLastTime = difftime( actualTime, hitTime );

    if( CheckHitIndicating() == true )
    {
        barBg.SetColor( Point( 0, 1, 0 ) );
    }
    else
    {
        barBg.SetColor( Point( 1, 1, 1 ) );
    }

    barBg.Draw();

    sprintf_s(pointsString, "%i", points);
    sprintf_s(playTimeString, "%.2lf", playTime);
    sprintf_s(bulletsString, "%i", bullets);

    Utils::Text::PutTextCamFollowing(Point(position.GetX() + 0.2, position.GetY() + 0.22, position.GetZ() - 0.5), Point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, pointsString);
    Utils::Text::PutTextCamFollowing(Point(position.GetX() + 0.2, position.GetY() + 0.24, position.GetZ() - 0.5), Point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, playTimeString);
    Utils::Text::PutTextCamFollowing(Point(position.GetX() + 0.2, position.GetY() + 0.26, position.GetZ() - 0.5), Point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, bulletsString);
}

InfoBar& InfoBar::GetInstance()
{
    //Inicjalizacja statycznego obiektu.
    //Obiekt zostanie utworzony przy pierwszym wywo³aniu tej metody
    //i tylko wtedy nast¹pi inicjalizacja przy pomocy konstruktora.
    //Ka¿de nastêpne wywo³anie jedynie zwróci referencjê tego obiektu.
    static InfoBar instance;
    return instance;
}
