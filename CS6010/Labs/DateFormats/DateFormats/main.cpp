//
//  main.cpp
//  DateFormats
//
//  Created by Taylor Dunn && Tyler Jette on 8/27/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    //"01/01/1999" becomes "January 1, 1999".
    string numericDate;
    string englishDate;
    cout << "Please enter in a date in the format \"mm/dd/yyyy\":" << endl;
    cin >> numericDate;

    string month = numericDate.substr(0,2);
    string day = numericDate.substr(3,2);
    string year = numericDate.substr(6,4);
    int dayAsInt = stoi(day);
    int monthAsInt = stoi(month);
    int yearAsInt = stoi(year);

    //Check for valid monthd
    if (monthAsInt < 0 || monthAsInt > 12){
        cout << "This is not a valid date" << endl;
        return 1;
    }
    //Check for valid day
    if (dayAsInt < 0 || dayAsInt > 31){
        cout << "This is not a valid date" << endl;
        return 1;
    }
    //Check for valid year
    if (yearAsInt < 1000 || yearAsInt > 9999){
        cout << "This is not a valid date" << endl;
        return 1;
    }
    //Check for valid day given a certain month (Pretend Leap Year isn't a thing...)
    if ( monthAsInt == 4 || monthAsInt == 6 || monthAsInt == 9 || monthAsInt == 11) {
        if (dayAsInt > 30) {
            cout << "This is not a valid date" << endl;
            return 1;
        }
    } else if (monthAsInt) {
        if (dayAsInt > 28){
            cout << "This is not a valid date" << endl;
            return 1;
        }
    } else {
        //Don't do anything
    }
    //Change numeric string to a character string
    if (month == "01"){
        month = "January";
    } else if (month == "02"){
        month = "February";
    } else if (month == "03"){
        month = "March";
    } else if (month == "04"){
        month = "April";
    } else if (month == "05"){
        month = "May";
    } else if (month == "06"){
        month = "June";
    } else if (month == "07"){
        month = "July";
    } else if (month == "08"){
        month = "August";
    } else if (month == "09"){
        month = "September";
    } else if (month == "10"){
        month = "October";
    } else if (month == "11"){
        month = "November";
    } else if (month == "12"){
        month = "December";
    }
    //Remove 0 on days from 01-09
    if (day.substr(0,1) == "0"){
        day = day.substr(1);
    }
    //Format into EnglishDate
    englishDate = month + " " + day + ", " + year;
    cout << englishDate << endl;
    
    //Part 2.5
    //Truncate year to be only the last 2 digits
    string newYear = year.substr(2,2);
    int newYearAsInt = stoi(newYear);
    //Determine whether date is a magic date
    if (dayAsInt * monthAsInt == newYearAsInt){
        cout << numericDate << " is a magic date! Hurray!" << endl;
    } else {
        cout << numericDate << " is not a magic date! Boo!" << endl;
    }
        return 0;
}
