#include "bullet.h"

Bullet::Bullet() {
    this->momentum = point(0, 0, 0);
    this->position = point(0, 0, 12);
}

Bullet::Bullet(point startPoint) {
    this->momentum = point(0, 0, 0);
    this->position = startPoint;
}

void Bullet::Draw() {
    glEnable( GL_LIGHTING );

    glColor3f(0.5,0.5,0.5);

    // Move bullet
    if( momentum != point(0, 0, 0) )
    {
        glPushMatrix();
         glTranslatef( this->position.GetX(), this->position.GetY(), this->position.GetZ() );
         glutSolidSphere(0.03, 20, 20);
         glLoadIdentity();
        glPopMatrix();

        position = position + momentum / 2.5;
    }
}

point Bullet::GetPosition() {
    return position;
}

point Bullet::GetMomentum() {
    return momentum;
}

void Bullet::GiveMomentum(point momentum) {
    this->momentum = momentum;
}
