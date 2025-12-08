/*
Author: Augustus Lin
Instructor: Tong Yi
Course: CSCI 135
Assignment Lab12 C

Write a program called pairwise.cpp that implements the function vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2) that returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments. If a vector has a smaller size than the other, consider extra entries from the shorter vectors as 0.
*/

#include <vector>//headers
#include <iostream>
using namespace std;

vector<int> sumPairWise( vector<int> &v1,  vector<int> &v2)
{
    vector<int> num;// a new vector for return
    int c=0; //counter for the larger vector
    if(v1.size()>v2.size())
    {
        for(int i=0;i<v2.size();i++)
        {
            num.push_back(v1[i]+v2[i]);
            c++;
        }
        while(c<v1.size())
        {
            num.push_back(v1[c]);
            c++;
        }
        return num;



    }
    else{
        for(int i=0;i<v1.size();i++)
        {
            num.push_back(v1[i]+v2[i]);
            c++;
        }
        while(c<v2.size())
        {
            num.push_back(v2[c]);
            c++;
        }
        return num;

    }
    return num;
}