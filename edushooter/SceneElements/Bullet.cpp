#include "bullet.h"

Bullet::Bullet() {
    this->momentum = Point(0, 0, 0);
    this->position = Point(0, 0, 12);
}

Bullet::Bullet(Point startPoint) {
    this->momentum = Point(0, 0, 0);
    this->position = startPoint;
}

void Bullet::Draw() {
    glEnable( GL_LIGHTING );

    glColor3f(0.5,0.5,0.5);

    // Move bullet
    if( momentum != Point(0, 0, 0) )
    {
        glPushMatrix();
         glTranslatef( this->position.GetX(), this->position.GetY(), this->position.GetZ() );
         glutSolidSphere(0.03, 20, 20);
         glLoadIdentity();
        glPopMatrix();

        position = position + momentum / 2.5;
    }
}

Point Bullet::GetPosition() {
    return position;
}

Point Bullet::GetMomentum() {
    return momentum;
}

void Bullet::GiveMomentum(Point momentum) {
    this->momentum = momentum;
}
