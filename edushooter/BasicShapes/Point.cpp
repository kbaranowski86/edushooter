#include "Point.h"

Point::Point() {}

Point::Point(double x = 0.0f, double y = 0.0f, double z = 0.0f){
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::ComputeLength(){
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Point::SetX(double value){
    this->x = value;
}

void Point::SetY(double value){
    this->y = value;
}

void Point::SetZ(double value){
    this->z = value;
}

void Point::SetCoords(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::GetX(){
     return x;
}

double Point::GetY(){
     return y;
}

double Point::GetZ(){
     return z;
}

void Point::normalize(){
     double length = ComputeLength();
     this->x = this->x / length;
     this->y = this->y / length;
     this->z = this->z / length;
}

Point Point::operator+(const Point& tmp) {
     return Point(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z);
}

Point Point::operator-(const Point& tmp){
     return Point( this->x - tmp.x, this->y - tmp.y, this->z - tmp.z);
}

Point Point::operator/(const double& tmp){
     return Point( this->x / tmp, this->y / tmp, this->z / tmp);
}

Point Point::operator*(const double& tmp){
     return Point( this->x * tmp, this->y * tmp, this->z * tmp);
}

Point& Point::operator=(const Point& tmp){
      if(&tmp==this) return *this;
      x = tmp.x;
      y = tmp.y;
      z = tmp.z;
      return *this;
}

bool Point::operator==(const Point& tmp){
    if( this->x == tmp.x && this->y == tmp.y && this->z == tmp.z )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Point::operator!=(const Point& tmp){
    if( !(this->x == tmp.x || this->y == tmp.y || this->z == tmp.z ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
