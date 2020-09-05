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

double monthlyAverage(vector<RainfallInfo>& rainData, string searchMonth);

//A vector of the months of the year
vector<string> createMonths();

//Takes RainfallInfo and calculates the average rainfall for each month and stores it in a vector of doubles
vector<double> averages(vector<RainfallInfo>& rainData);

//Finds the total average rainfall for a vector<RainfallInfo>
double totalAverage(vector<double>& rainData);


int findSmallest(vector<RainfallInfo>& averages, int start);

//Sorts data in ascending order and returns the 4 smallest values
vector<RainfallInfo> sortRainfallSmallest(vector<RainfallInfo>& rainData);

int findLargest(vector<RainfallInfo>& averages, int start);

vector<RainfallInfo> sortRainfallLargest(vector<RainfallInfo>& rainData);

string vectorToString(vector<double> values);

double returnValue(vector<RainfallInfo>& rainData, int index);

RainfallInfo findMedian(vector<RainfallInfo>& rainData);

#endif /* Analysis_hpp */
