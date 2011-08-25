class InfoBar
{
    private:
        int points;
        double playTime;
        int bullets;
        point position;

        Rect barBg;

    public:
        InfoBar()
        {
            position = point( 0, 0, 0);
            barBg = Rect( point( 0.15, 0.29, position.GetZ() -0.51 ) , point( 0.3, 0.215, position.GetZ() -0.51 ), point( 0, 0, -1 ), Utils::XY, "", true );
        }
        InfoBar(const InfoBar &);
        InfoBar& operator=(const InfoBar&);

        void SetPoints( int points )
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

        void DrawBonusInfo( int correctAnswerIndex )
        {
            char* caption = "Numer klocka z bonusem: ";
            char correctAnswerIndexString[100];

            sprintf( correctAnswerIndexString, "%i", correctAnswerIndex );

            Utils::PutTextCamFollowing(point(position.GetX() - 0.1, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, caption);
            Utils::PutTextCamFollowing(point(position.GetX() + 0.1, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, correctAnswerIndexString);
        }

        void DrawBar()
        {
            char pointsString[100];
            char playTimeString[100];
            char bulletsString[100];

            barBg.Draw();

            sprintf(pointsString, "%i", points);
            sprintf(playTimeString, "%.2lf", playTime);
            sprintf(bulletsString, "%i", bullets);

            Utils::PutTextCamFollowing(point(position.GetX() + 0.2, position.GetY() + 0.22, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, pointsString);
            Utils::PutTextCamFollowing(point(position.GetX() + 0.2, position.GetY() + 0.24, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, playTimeString);
            Utils::PutTextCamFollowing(point(position.GetX() + 0.2, position.GetY() + 0.26, position.GetZ() - 0.5), point(0.0, 0.0, 0.0), GLUT_BITMAP_TIMES_ROMAN_24, bulletsString);
        }

        static InfoBar& GetInstance()
        {
            //Inicjalizacja statycznego obiektu.
            //Obiekt zostanie utworzony przy pierwszym wywo³aniu tej metody
            //i tylko wtedy nast¹pi inicjalizacja przy pomocy konstruktora.
            //Ka¿de nastêpne wywo³anie jedynie zwróci referencjê tego obiektu.
            static InfoBar instance;
            return instance;
        }
};
