//
//  Analysis.cpp
//  RainfallAnalysis
//
//  Created by Taylor Dunn on 9/3/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Analysis.hpp"


vector<string> createMonths(){
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months;
}

double monthlyAverage(vector<RainfallInfo>& rainData, string searchMonth){
    double totalRain = 0;
    int monthCount = 0;
    for (RainfallInfo dataPoint : rainData){
        if (dataPoint.month == searchMonth){
            totalRain += dataPoint.rainfall;
            monthCount++;
        }
    }
    double average = totalRain/monthCount;
    return average;
}

vector<double> averages(vector<RainfallInfo>& rainData){
    vector<double> monthlyAverages;
    for (string month : createMonths()){
        monthlyAverages.push_back(monthlyAverage(rainData, month));
    }
    return monthlyAverages;
}

double totalAverage(vector<double>& rainData){
    double total = 0;
    for(double month : rainData){
        total += month;
    }
    return total/12;
}

int findSmallest(vector<RainfallInfo>& averages, int start){
    int minLocation = start;
    for (int i = start; i < averages.size(); i++){
        if (averages[i].rainfall< averages[minLocation].rainfall){
            minLocation = i;
        }
    }
    return minLocation;
}

vector<RainfallInfo> sortRainfallSmallest(vector<RainfallInfo>& rainData){
    for(int i =0; i <rainData.size(); i++){
        double smallest = findSmallest(rainData, i);
        swap(rainData[i], rainData[smallest]);
    }
    return rainData;
}

int findLargest(vector<RainfallInfo>& averages, int start){
    int maxLocation = start;
    for (int i = start; i < averages.size(); i++){
        if (averages[i].rainfall > averages[maxLocation].rainfall){
                maxLocation = i;
            }
        }
    return maxLocation;
}

vector<RainfallInfo> sortRainfallLargest(vector<RainfallInfo>& rainData){
        for(int i =0; i <rainData.size(); i++){
            double smallest = findLargest(rainData, i);
            swap(rainData[i], rainData[smallest]);
        }
    return rainData;
}

RainfallInfo findMedian(vector<RainfallInfo>& rainData){
    int elements = (int)rainData.size();
    return rainData[elements/2];
}
