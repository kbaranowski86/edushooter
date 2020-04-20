#include<GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point{  //definicja punktu w przestrzeni

    private:
       double x, y, z;

    public:
       Point();
       Point(double, double, double);

       double ComputeLength();
       void SetX(double);
       void SetY(double);
       void SetZ(double);
       void SetCoords(double, double, double);
       double GetX();
       double GetY();
       double GetZ();
       void normalize();
       Point operator+(const Point&);
       Point operator-(const Point&);
       Point operator/(const double&);
       Point operator*(const double&);
       Point& operator=(const Point&);
       bool operator==(const Point&);
       bool operator!=(const Point&);
};

#endif
