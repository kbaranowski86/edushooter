#include <time.h>
#include "..\BasicShapes\Point.h"
#include "..\BasicShapes\Rect.h"
#ifndef INFOBAR_H
#define INFOBAR_H

class InfoBar
{
    private:
        int points;
        double playTime;
        int bullets;
        Point position;

        time_t hitTime, actualTime;
        float hitIndicatingLastTime;

        Rect barBg;

    public:
        InfoBar();
        InfoBar(const InfoBar &);
        InfoBar& operator=(const InfoBar&);

        void SetPoints( int );
        void SetPlayTime(double);
        void SetBullets(int);
        void SetHitIndicating();
        bool CheckHitIndicating();
        void SetAll(int points, double playTime, int bullets);
        void DrawBonusInfo( int correctAnswerIndex );
        void Draw();
        static InfoBar& GetInstance();
};

#endif // INFOBAR_H
