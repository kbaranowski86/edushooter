#include "point.h"

point::point() {}

point::point(double x = 0.0f, double y = 0.0f, double z = 0.0f){
    this->x = x;
    this->y = y;
    this->z = z;
}

double point::ComputeLength(){
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void point::SetX(double value){
    this->x = value;
}

void point::SetY(double value){
    this->y = value;
}

void point::SetZ(double value){
    this->z = value;
}

void point::SetCoords(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double point::GetX(){
     return x;
}

double point::GetY(){
     return y;
}

double point::GetZ(){
     return z;
}

void point::normalize(){
     double length = ComputeLength();
     this->x = this->x / length;
     this->y = this->y / length;
     this->z = this->z / length;
}

point point::operator+(const point& tmp) {
     return point(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z);
}

point point::operator-(const point& tmp){
     return point( this->x - tmp.x, this->y - tmp.y, this->z - tmp.z);
}

point point::operator/(const double& tmp){
     return point( this->x / tmp, this->y / tmp, this->z / tmp);
}

point point::operator*(const double& tmp){
     return point( this->x * tmp, this->y * tmp, this->z * tmp);
}

point& point::operator=(const point& tmp){
      if(&tmp==this) return *this;
      x = tmp.x;
      y = tmp.y;
      z = tmp.z;
      return *this;
}

bool point::operator==(const point& tmp){
    if( this->x == tmp.x && this->y == tmp.y && this->z == tmp.z )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool point::operator!=(const point& tmp){
    if( !(this->x == tmp.x || this->y == tmp.y || this->z == tmp.z ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
