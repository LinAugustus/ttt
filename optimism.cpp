/*
Author: Augustus Lin
Instructor: Tong Yi
Course: CSCI 135
Assignment Lab12 B

Make a program called optimism.cpp that implements the function vector<int> goodVibes(const vector<int>& v); that, given a vector of integers, returns a vector with only the positive integers in the same order.
*/



#include <vector>
#include <iostream>
using namespace std;

vector<int> goodVibes(const vector<int> v)
{
    vector<int> num;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            num.push_back(v[i]);
    }
    return num;
}