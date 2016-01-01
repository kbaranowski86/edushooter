#include "score.h"

Score::Score()
{
     this->timeOfGame = 0;
     points = 0;
}

void Score::IncreasePointsOf(int value)
{
    points += value;
}

int Score::GetPoints()
{
    return points;
}

void Score::TimeStart()
{
    time(&startTime);
}

void Score::TimeProgress()
{
    time(&actualTime);
    timeOfGame = difftime(actualTime, startTime);
}

float Score::GetTimeOfGame()
{
    return timeOfGame;
}

Score& Score::GetInstance()
{
    //Inicjalizacja statycznego obiektu.
    //Obiekt zostanie utworzony przy pierwszym wywo³aniu tej metody
    //i tylko wtedy nast¹pi inicjalizacja przy pomocy konstruktora.
    //Ka¿de nastêpne wywo³anie jedynie zwróci referencjê tego obiektu.
    static Score instance;
    return instance;
}
