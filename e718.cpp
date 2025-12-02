/*
This program contains a struct Triangle with 3 point*/

#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    
    double x;
    double y;

   
};

 double distance(Point a, Point b)
    {
        return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
        
    }

struct Triangle{
    Point a;
    Point b;
    Point c;
};

double perimeter(Triangle t)
{
    return distance(t.a,t.b)+distance(t.a,t.c)+distance(t.b,t.c);
}