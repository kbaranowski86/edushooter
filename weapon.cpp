#include "weapon.h"

Weapon::Weapon(point position, int bulletsNum, BoxSetSet* boxSetSet, Room* room): bulletsNum(bulletsNum)
{
    this->position = position;
    this->boxSetSet = boxSetSet;
    this->room = room;
    this->bullets = new Bullet[bulletsNum];

    int i;
    for(i = 0; i < bulletsNum; i++)
    {
        this->bullets[i] = Bullet( position );
    }
    this->currentBullet = 0;
}

void Weapon::ChangeDirection(double x, double y){
    direction.SetX(x);
    direction.SetY(y);
    direction.SetZ( - 12.0 );

    direction.normalize();
}

void Weapon::DrawViewFinder()
{
    glDisable( GL_LIGHTING );
    glColor3f(1, 0, 0);
    glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

      // Horizontal line
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f (- 0.1, 0.004, -3);
        glVertex3f (0.1, 0.004, -3);
        glVertex3f (0.1, -0.004, -3);
        glVertex3f (- 0.1, -0.004, -3);
    glEnd();

      // Vertical line
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f ( - 0.004, 0.1, -3);
        glVertex3f (0.004, 0.1, -3);
        glVertex3f (0.004, -0.1, -3);
        glVertex3f ( - 0.004,  -0.1, -3);
    glEnd();

    glPopMatrix();
}

void Weapon::DrawBullets()
{
    int i, j;
    for( i = 0; i < this->bulletsNum; i++ )
    {
        for( j = 0; j < 3; j++ )
        {
            boxSetSet->boxSets[j]->CheckBoxesForHit(&bullets[i]);
        }

        room->CheckIfHit(&bullets[i]);
        this->bullets[i].Draw();
    }
    glLoadIdentity();
}

void Weapon::Shot()
{
    if( currentBullet < bulletsNum )
    {
        bullets[currentBullet].GiveMomentum(direction);
        currentBullet++;
    }
}

int Weapon::GetLastBulletsNum()
{
    return bulletsNum - currentBullet;
}
