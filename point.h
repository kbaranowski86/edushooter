#include <stdio.h>
#include <math.h>
#include <iostream>

#ifndef POINT_H
#define POINT_H

using namespace std;

class point{  //definicja punktu w przestrzeni

    private:
       double x, y, z;

    public:
       point();
       point(double, double, double);

       double ComputeLength();
       void SetX(double);
       void SetY(double);
       void SetZ(double);
       void SetCoords(double, double, double);
       double GetX();
       double GetY();
       double GetZ();
       void normalize();
       point operator+(const point&);
       point operator-(const point&);
       point operator/(const double&);
       point operator*(const double&);
       point& operator=(const point&);
       bool operator==(const point&);
       bool operator!=(const point&);
};

#endif
