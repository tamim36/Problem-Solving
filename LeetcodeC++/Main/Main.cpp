// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Solution.h"

int main()
{
    std::cout << "Hello World!\n";
    //vector<int> vect{ 35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49 };
    vector<int> vect{ 10, 9, 14 };
    int a = Solution::maximumTop(vect, 5);
    cout << a << endl;
}

