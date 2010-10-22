// project party libraries
#include "utils.h"

class InfoBar
{
      private:
              int points;
              double playTime;
              int bullets;
              point position;
              
      public:
             InfoBar(point initialPosition)
             {
                  position = initialPosition;
             }
             
             void SetPoints(int points)
             {
                  this->points = points;
             }
             
             void SetPlayTime(double playTime)
             {
                  this->playTime = playTime;
             }
             
             void SetBullets(int bullets)
             {
                  this->bullets = bullets;
             }
             
             void SetAll(int points, double playTime, int bullets)
             {
                  this->points = points;
                  this->playTime = playTime;
                  this->bullets = bullets;
             }
             
             void DrawBar()
             {
                  char pointsString[100];
                  char playTimeString[100];
                  char bulletsString[100];
                  
                  sprintf(pointsString, "%i", points);
                  sprintf(playTimeString, "%.2lf", playTime);
                  sprintf(bulletsString, "%i", bullets);
                  
                  Utils::PutText(point(position.GetX() + 0.2, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, pointsString);
                  Utils::PutText(point(position.GetX() + 0.2, position.GetY() + 0.24, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, playTimeString);
                  Utils::PutText(point(position.GetX() + 0.2, position.GetY() + 0.26, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, bulletsString);
             }
};
