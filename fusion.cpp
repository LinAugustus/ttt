/*
Author: Augustus Lin
Instructor: Tong Yi
Course: CSCI 135
Assignment Lab12 C

Make a program called fusion.cpp that implements the function void gogeta(vector<int> &goku, vector<int> &vegeta) that appends elements of the second vector into the first and empties the second vector. For example:
*/

#include <vector>
#include <iostream>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
    while(!vegeta.empty())
    {
        goku.push_back(vegeta[0]);
        vegeta.erase(vegeta.begin());
    }
}