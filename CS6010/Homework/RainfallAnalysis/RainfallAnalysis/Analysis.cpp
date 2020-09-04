//
//  Analysis.cpp
//  RainfallAnalysis
//
//  Created by Taylor Dunn on 9/3/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Analysis.hpp"

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
vector<string> createMonths(){
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months;
}

vector<double> averages(vector<RainfallInfo>& rainData){
    vector<double> monthlyAverages;
    double januaryAverage = monthlyAverage(rainData, "January");
    double februaryAverage = monthlyAverage(rainData, "February");
    double marchAverage = monthlyAverage(rainData, "March");
    double aprilAverage = monthlyAverage(rainData, "April");
    double mayAverage = monthlyAverage(rainData, "May");
    double juneAverage = monthlyAverage(rainData, "June");
    double julyAverage = monthlyAverage(rainData, "July");
    double augustAverage = monthlyAverage(rainData, "August");
    double septemberAverage = monthlyAverage(rainData, "September");
    double octoberAverage = monthlyAverage(rainData, "October");
    double novemberAverage = monthlyAverage(rainData, "November");
    double decemberAverage = monthlyAverage(rainData, "December");
    monthlyAverages.push_back(januaryAverage);
    monthlyAverages.push_back(februaryAverage);
    monthlyAverages.push_back(marchAverage);
    monthlyAverages.push_back(aprilAverage);
    monthlyAverages.push_back(mayAverage);
    monthlyAverages.push_back(juneAverage);
    monthlyAverages.push_back(julyAverage);
    monthlyAverages.push_back(augustAverage);
    monthlyAverages.push_back(septemberAverage);
    monthlyAverages.push_back(octoberAverage);
    monthlyAverages.push_back(novemberAverage);
    monthlyAverages.push_back(decemberAverage);
    return monthlyAverages;
}

double totalAverage(vector<RainfallInfo>& rainData){
    double januaryAverage = monthlyAverage(rainData, "January");
    double februaryAverage = monthlyAverage(rainData, "February");
    double marchAverage = monthlyAverage(rainData, "March");
    double aprilAverage = monthlyAverage(rainData, "April");
    double mayAverage = monthlyAverage(rainData, "May");
    double juneAverage = monthlyAverage(rainData, "June");
    double julyAverage = monthlyAverage(rainData, "July");
    double augustAverage = monthlyAverage(rainData, "August");
    double septemberAverage = monthlyAverage(rainData, "September");
    double octoberAverage = monthlyAverage(rainData, "October");
    double novemberAverage = monthlyAverage(rainData, "November");
    double decemberAverage = monthlyAverage(rainData, "December");
    double averageRainfall = (januaryAverage + februaryAverage + marchAverage + aprilAverage + mayAverage + juneAverage + julyAverage + augustAverage + septemberAverage + octoberAverage + novemberAverage + decemberAverage) /12;
    return averageRainfall;
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

vector<double> sortRainfallSmallest(vector<RainfallInfo>& rainData){
    vector<double> lowestFour;
    for(int i =0; i <rainData.size(); i++){
        double smallest = findSmallest(rainData, i);
        swap(rainData[i], rainData[smallest]);
    }
    for (int i = 0; i < 4; i++){
        lowestFour.push_back(rainData[i].rainfall);
    }
    return lowestFour;
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

vector<double> sortRainfallLargest(vector<RainfallInfo>& rainData){
    vector<double> largestFour;
        for(int i =0; i <rainData.size(); i++){
            double smallest = findLargest(rainData, i);
            swap(rainData[i], rainData[smallest]);
        }
        for (int i = 0; i < 4; i++){
            largestFour.push_back(rainData[i].rainfall);
        }
        return largestFour;
    }

string vectorToString(vector<double> values){
    string s;
    for (int i = 0; i < values.size(); i ++){
        if (i!=values.size()){
            s+= to_string(values[i]) + " ";
        }
        else{
            s+= to_string(values[i]);
        }
    }
    return s;
}

double returnValue(vector<RainfallInfo>& rainData, int index){
    return rainData[index].rainfall;
}
//double findMedian(vector<RainfallInfo>& rainData){
//    vector<double> sorted = //TODO make a sorted month function
//    double median;
//    int elements = (int)rainData.size();
//    if (elements % 2 ==1){
//        median = sorted[(elements/2) +1];
//    }
//    else{
//        median = sorted[elements/2];
//    }
//    return median;
//}
