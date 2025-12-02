/*
This program contain a struct named Point with 2 data member, and a distance method*/
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


