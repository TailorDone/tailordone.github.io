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

//A vector of the months of the year
vector<string> createMonths();

//Returns an individual months' average rainfall
double monthlyAverage(vector<RainfallInfo>& rainData, string searchMonth);

//Takes RainfallInfo and calculates the average rainfall for each month and stores the values as a vector of doubles
vector<double> averages(vector<RainfallInfo>& rainData);

//Finds the total average rainfall for a vector<RainfallInfo>
double totalAverage(vector<double>& rainData);

// Finds the smallest element in a vector
int findSmallest(vector<RainfallInfo>& averages, int start);

//Sorts data in ascending order
vector<RainfallInfo> sortRainfallSmallest(vector<RainfallInfo>& rainData);

//Finds the largest element in a vector
int findLargest(vector<RainfallInfo>& averages, int start);

//sorts data in descending order
vector<RainfallInfo> sortRainfallLargest(vector<RainfallInfo>& rainData);

//Finds the median based on RainfallInfo.rainfall
RainfallInfo findMedian(vector<RainfallInfo>& rainData);

#endif /* Analysis_hpp */
