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
    Score( const Score& );
    Score& operator=(const Score&);

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

    static Score& GetInstance()
    {
        //Inicjalizacja statycznego obiektu.
        //Obiekt zostanie utworzony przy pierwszym wywo³aniu tej metody
        //i tylko wtedy nast¹pi inicjalizacja przy pomocy konstruktora.
        //Ka¿de nastêpne wywo³anie jedynie zwróci referencjê tego obiektu.
        static Score instance;
        return instance;
    }
};
