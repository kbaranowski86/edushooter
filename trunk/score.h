//System libraries
#include <time.h>

class Score
{

private:      
      
      time_t startTime, actualTime;
      double timeOfGame;
      int points;
      
public:

      Score()
      {
             this->timeOfGame = 0;
             points = 0;
      }
      
      void IncreasePointsOf(int value)
      {
           points += value;
      }
      
      int GetPoints()
      {
          return points;
      }
      
      void TimeStart()
      {
           time(&startTime);
      }
      
      void TimeProgress()
      {
           time(&actualTime);
           timeOfGame = difftime(actualTime, startTime);
      }
      
      float GetTimeOfGame()
      {
          return timeOfGame;
      }
};
