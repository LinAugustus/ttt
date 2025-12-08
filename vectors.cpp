/*
Author: Augustus Lin
Instructor: Tong Yi
Course: CSCI 135
Assignment Lab12 A

A big benefit of vectors is their ability to be returned from functions. For this task, program a function called vector<int> makeVector(int n) that returns a vector of n integers that range from 0 to n-1. Call your program vectors.cpp. Your function must be implemented outside the main function and must return a vector.*/

#include <iostream>//headers for vector
#include <vector>
using namespace std;

vector<int> makeVector(int n)//given an parameter n as int
{
    vector<int> num;
    for(int i=0;i<n;i++)//add all number in range of [0,n-1]
    {
        num.push_back(i);
    }
    return num;


}