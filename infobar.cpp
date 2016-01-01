#include "infobar.h"

InfoBar::InfoBar() {
    hitTime = 0;
    position = point( 0, 0, 0);
    barBg = Rect( point( 0.15, 0.29, position.GetZ() -0.51 ) , point( 0.3, 0.215, position.GetZ() -0.51 ), point( 0, 0, -1 ), point( 1, 1, 1), Utils::XY, "", true, false );
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
    char* caption = "Numer klocka z bonusem: ";
    char correctAnswerIndexString[100];

    sprintf( correctAnswerIndexString, "%i", correctAnswerIndex );

    Utils::PutTextCamFollowing(point(position.GetX() - 0.1, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, caption);
    Utils::PutTextCamFollowing(point(position.GetX() + 0.1, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, correctAnswerIndexString);
}

void InfoBar::Draw()
{
    char pointsString[100];
    char playTimeString[100];
    char bulletsString[100];

    hitIndicatingLastTime = difftime( actualTime, hitTime );

    if( CheckHitIndicating() == true )
    {
        barBg.SetColor( point( 0, 1, 0 ) );
    }
    else
    {
        barBg.SetColor( point( 1, 1, 1 ) );
    }

    barBg.Draw();

    sprintf(pointsString, "%i", points);
    sprintf(playTimeString, "%.2lf", playTime);
    sprintf(bulletsString, "%i", bullets);

    Utils::PutTextCamFollowing(point(position.GetX() + 0.2, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, pointsString);
    Utils::PutTextCamFollowing(point(position.GetX() + 0.2, position.GetY() + 0.24, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, playTimeString);
    Utils::PutTextCamFollowing(point(position.GetX() + 0.2, position.GetY() + 0.26, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, bulletsString);
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
