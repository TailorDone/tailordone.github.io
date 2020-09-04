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
    ofstream outs("rainfall_results.txt");
    outs << "CS 6010 Rainfall Analysis" << endl;
    outs << "Rainfall Data for " << city << endl;
    outs << endl;
    outs << fixed << setprecision(2) << "The overall average rainfall amount is " << totalAverage(atlantaRainfall) << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for January is " << monthlyAverage(atlantaRainfall, "January") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for February is " << monthlyAverage(atlantaRainfall, "February") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for March is " << monthlyAverage(atlantaRainfall, "March") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for April is " << monthlyAverage(atlantaRainfall, "April") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for May is " << monthlyAverage(atlantaRainfall, "May") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for June is " << monthlyAverage(atlantaRainfall, "June") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for July is " << monthlyAverage(atlantaRainfall, "July") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for August is " << monthlyAverage(atlantaRainfall, "August") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for September is " << monthlyAverage(atlantaRainfall, "September") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for October is " << monthlyAverage(atlantaRainfall, "October") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for November is " << monthlyAverage(atlantaRainfall, "November") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for December is " << monthlyAverage(atlantaRainfall, "December") << " inches." << endl;
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four wettest months are: " << endl;
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four driest months are: " << endl;
    //vector<double> lowest = sortRainfallSmallest(atlantaRainfall); No matching function call?
    //string lowestString = vectorToString(lowest);
    

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
    outs << fixed << setprecision(2) << "The average rainfall amount for January is " << monthlyAverage(maconRainfall, "January") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for February is " << monthlyAverage(maconRainfall, "February") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for March is " << monthlyAverage(maconRainfall, "March") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for April is " << monthlyAverage(maconRainfall, "April") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for May is " << monthlyAverage(maconRainfall, "May") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for June is " << monthlyAverage(maconRainfall, "June") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for July is " << monthlyAverage(maconRainfall, "July") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for August is " << monthlyAverage(maconRainfall, "August") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for September is " << monthlyAverage(maconRainfall, "September") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for October is " << monthlyAverage(maconRainfall, "October") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for November is " << monthlyAverage(maconRainfall, "November") << " inches." << endl;
    outs << fixed << setprecision(2) << "The average rainfall amount for December is " << monthlyAverage(maconRainfall, "December") << " inches." << endl;
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four wettest months are: " << endl;
    outs << fixed << setprecision(2) << "The rain amounts (in inches) of the four driest months are: " << endl;
    //vector<double> largest = sortRainfallLargest(atlantaRainfall); No matching function call?
    //string largestString = vectorToString(largest);
   
    return 0;
}
