//
//  main.cpp
//  RainfallAnalysis
//
//  Created by Taylor Dunn on 9/3/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Analysis.hpp"

int main(int argc, const char * argv[]) {
    //Variables
    string city, month;
    int year;
    double rainfall;
    vector<RainfallInfo> cityRainfall;
    vector<string> months = createMonths();
            
    //Input stream for Atlanta
    ifstream ins("atlanta.txt"); //user must hardcode text file they want to input
    ins >> city;for (int i = 0; i < 240; i++){
    ins >> month >> year >> rainfall;
        RainfallInfo info = {month, year, rainfall};
        cityRainfall.push_back(info);
    }
    //Find monthly averages for atlanta
    vector<double> monthlyAverages = averages(cityRainfall);
    //Output analysis for Atlanta
    ofstream outs("rainfall_results.txt");
    outs << "CS 6010 Rainfall Analysis" << endl;
    outs << "Rainfall Data for " << city << endl;
    outs << endl;
    outs << fixed << setprecision(2) << "The overall average rainfall amount is " << totalAverage(monthlyAverages) << " inches." << endl;
    for (string month : months){
        outs << fixed << setprecision(2) << "The average rainfall amount for " << month << " is " << monthlyAverage(cityRainfall, month) << " inches." << endl;
    }
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four wettest months are: " ;
    vector<RainfallInfo> cityLargest = sortRainfallLargest(cityRainfall);
    for(int i = 0; i < 4; i++){
        outs << fixed << setprecision(2) << cityLargest[i].rainfall << " ";
    }
    outs << endl;
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four driest months are: " ;
    vector<RainfallInfo> citySmallest = sortRainfallSmallest(cityRainfall);
    for(int i = 0; i < 4; i++){
        outs << fixed << setprecision(2) << cityRainfall[i].rainfall << " ";
    }
    outs << endl;
    RainfallInfo cityMedian = findMedian(citySmallest);
    outs << fixed << setprecision(2) << "The median month is: " << cityMedian.month << " " << cityMedian.year << " " << cityMedian.rainfall << endl;
    
//    vector<RainfallInfo> maconRainfall;
//    //Input stream for Macon
//    ifstream ins2("macon.txt");
//    ins2 >> city;for (int i = 0; i < 240; i++){
//    ins2 >> month >> year >> rainfall;
//        RainfallInfo info = {month, year, rainfall};
//        maconRainfall.push_back(info);
//    }
//    //Find monthly averages for Macon
//    vector<double> maconMonthlyAverages = averages(maconRainfall);
//    //Output analysis for Macon
//    outs << "Rainfall Data for " << city << endl;
//    outs << endl;
//    outs << fixed << setprecision(2) << "The overall average rainfall amount is " << totalAverage(monthlyAverages) << " inches." << endl;
//    for (string month : months){
//    outs << fixed << setprecision(2) << "The average rainfall amount for " << month << " is " << monthlyAverage(maconRainfall, month) << " inches." << endl;
//    }
//    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four wettest months are: " ;
//    vector<RainfallInfo> maconLargest = sortRainfallLargest(maconRainfall);
//    for(int i = 0; i < 4; i++){
//        outs << fixed << setprecision(2) << maconLargest[i].rainfall << " ";
//    }
//    outs << endl;
//    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four driest months are: " ;
//    vector<RainfallInfo> maconSmallest = sortRainfallSmallest(maconRainfall);
//    for(int i = 0; i < 4; i++){
//    outs << fixed << setprecision(2) << maconSmallest[i].rainfall << " ";
//    }
//    outs << endl;
//    RainfallInfo maconMedian = findMedian(maconSmallest);
//    outs << fixed << setprecision(2) << "The median month is: " << maconMedian.month << " " << maconMedian.year << " " << maconMedian.rainfall << endl;
    return 0;
}
