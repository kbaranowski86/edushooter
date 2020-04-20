//System libraries
#include <time.h>
#ifndef SCORE_H
#define SCORE_H

class Score
{

private:

      time_t startTime, actualTime;
      double timeOfGame;
      int points;

public:

    Score();
    Score( const Score& );
    Score& operator=(const Score&);

    void IncreasePointsOf(int);
    int GetPoints();
    void TimeStart();
    void TimeProgress();
    float GetTimeOfGame();
    static Score& GetInstance();
};
#endif // SCORE_H
