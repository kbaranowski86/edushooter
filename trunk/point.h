#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class point{  //definicja punktu w przestrzeni

    private:
       double x, y, z;

    public:
       point(double x = 0.0f, double y = 0.0f, double z = 0.0f){
            this->x = x;
            this->y = y;
            this->z = z;
       }

       double ComputeLength(){
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
       }

       void SetX(double value){
            this->x = value;
       }

       void SetY(double value){
            this->y = value;
       }

       void SetZ(double value){
            this->z = value;
       }

       void SetCoords(double x, double y, double z)
       {
            this->x = x;
            this->y = y;
            this->z = z;
       }

       double GetX(){
             return x;
       }

       double GetY(){
             return y;
       }

       double GetZ(){
             return z;
       }

       void normalize(){
             double length = ComputeLength();
             this->x = this->x / length;
             this->y = this->y / length;
             this->z = this->z / length;
       }

       point operator+(const point& tmp){
             return point(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z);
       }

       point operator-(const point& tmp){
             return point( this->x - tmp.x, this->y - tmp.y, this->z - tmp.z);
       }

       point operator/(const double& tmp){
             return point( this->x / tmp, this->y / tmp, this->z / tmp);
       }

       point operator*(const double& tmp){
             return point( this->x * tmp, this->y * tmp, this->z * tmp);
       }

       point& operator=(const point& tmp){
              if(&tmp==this) return *this;
              x = tmp.x;
              y = tmp.y;
              z = tmp.z;
              return *this;
       }

       bool operator==(const point& tmp){
            if( this->x == tmp.x && this->y == tmp.y && this->z == tmp.z )
            {
                return true;
            }
            else
            {
                return false;
            }
       }

       bool operator!=(const point& tmp){
            if( !(this->x == tmp.x || this->y == tmp.y || this->z == tmp.z ) )
            {
                return true;
            }
            else
            {
                return false;
            }
       }

};
