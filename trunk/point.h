#include <stdio.h>
#include <math.h>

class point{  //definicja punktu w przestrzeni
       
    private:
       float x, y, z;
    
    public:
       point(float x = 0, float y = 0, float z = 0){
            this->x = x;
            this->y = y;
            this->z = z;            
       }
       
       float ComputeLength(){
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
       }
       
       void SetX(float value){
            this->x = value;
       }
       
       void SetY(float value){
            this->y = value;
       }
       
       void SetZ(float value){
            this->z = value;
       }
       
       void SetCoords(float x, float y, float z)
       {
            this->x = x;
            this->y = y;
            this->z = z;
       }
       
       float GetX(){
             return x;
       }
       
       float GetY(){
             return y;
       }
       
       float GetZ(){
             return z;
       }
       
       void normalize(){
             float length = ComputeLength();
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
       
       point operator/(const float& tmp){
             return point( this->x / tmp, this->y / tmp, this->z / tmp);
       }
       
       point operator*(const float& tmp){
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
