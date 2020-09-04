//
//  Analysis.hpp
//  RainfallAnalysis
//
//  Created by Taylor Dunn on 9/3/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef Analysis_hpp
#define Analysis_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

struct RainfallInfo{
    string month;
    int year;
    double rainfall;
};

//Takes RainfallInfo and calculates the average rainfall for a given month
double monthlyAverage(vector<RainfallInfo>& rainData, string searchMonth);

//Finds the total average rainfall for a vector<RainfallInfo>
double totalAverage(vector<RainfallInfo>& rainData);

//Finds the smallest value in a vector of doubles
int findSmallest(vector<double>& averages, int start);

//Sorts data in ascending order and returns the 4 smallest values
vector<double> sortRainfallSmallest(vector<double>& rainData);

//Finds the largest value in a vector of doubles
int findLargest(vector<double>& averages, int start);

//Sorts data in descending order and returns the 4 largest values
vector<double> sortRainfallLargest(vector<double>& rainData);

//Takes a vector and turns it into a string
string printVector(vector<double>& rainData);

//Convert a vector to a string
string vectorToString(vector<double> values);
#endif /* Analysis_hpp */
