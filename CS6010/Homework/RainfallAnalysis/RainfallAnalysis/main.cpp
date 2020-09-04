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
    ifstream ins("atlanta.txt");
    string city;
    ins >> city;
    string month;
    int year;
    double rainfall;
    vector<RainfallInfo> atlantaRainfall;
    for (int i = 0; i < 240; i++){
    ins >> month >> year >> rainfall;
        RainfallInfo info = {month, year, rainfall};
        atlantaRainfall.push_back(info);
    }
    vector<string> months = createMonths();

    ofstream outs("rainfall_results.txt");
    outs << "CS 6010 Rainfall Analysis" << endl;
    outs << "Rainfall Data for " << city << endl;
    outs << endl;
    outs << fixed << setprecision(2) << "The overall average rainfall amount is " << totalAverage(atlantaRainfall) << " inches." << endl;
    for (string month : months){
      outs << fixed << setprecision(2) << "The average rainfall amount for " << month << " is " << monthlyAverage(atlantaRainfall, month) << " inches." << endl;
    }
    vector<double> largest = sortRainfallLargest(atlantaRainfall);
    string largestString = vectorToString(largest);
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four wettest months are: " << largestString <<endl;
    vector<double> lowest = sortRainfallSmallest(atlantaRainfall);
    string lowestString = vectorToString(lowest);
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four driest months are: " << lowestString<< endl;
    
    ifstream ins2("macon.txt");
    ins2 >> city;
    vector<RainfallInfo> maconRainfall;
    for (int i = 0; i < 240; i++){
    ins2 >> month >> year >> rainfall;
        RainfallInfo info = {month, year, rainfall};
        maconRainfall.push_back(info);
    }
    outs << endl;
    outs << "Rainfall Data for " << city << endl;
    outs << fixed << setprecision(2) << "The overall average rainfall amount is " << totalAverage(maconRainfall) << " inches." << endl;
    for (string month : months){
      outs << fixed << setprecision(2) << "The average rainfall amount for " << month << " is " << monthlyAverage(maconRainfall, month) << " inches." << endl;
    }
    vector<double> largest2 = sortRainfallLargest(maconRainfall);
    string largest2String = vectorToString(largest2);
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four wettest months are: " << largestString <<endl;
    vector<double> lowest2 = sortRainfallSmallest(maconRainfall);
    string lowest2String = vectorToString(lowest2);
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four driest months are: " << lowestString<< endl;
   
    return 0;
}
