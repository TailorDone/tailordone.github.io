//
//  main.cpp
//  FunctionsAndTesting
//
//  Created by Taylor Dunn on 8/28/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

// Variable gives a name to data
// Function gives a name to code
// Two aspects to functions. Defining and calling.

int readInt(string prompt){
    cout << prompt << endl;
    int var;
    cin >> var;
    return var;
}

void repeatChar(char c, int n){
    for (int i = 0; i < n; i++){
        cout << c;
    }
    cout << endl;
}

int g(int a) {
    return a*2;
}

int f(int x, int y){
    int res = g(x) + (g(y));
    return res;
}

int main(int argc, const char * argv[]) {
    // double theta = atan2(xVar,yVar);
    // This is tangent inverse.
    double theta = atan2(3,3);
    cout << theta << endl;
    // double xsquared = pow(x,2);
    double twoToTheThird = pow (2, 3);
    cout << twoToTheThird << endl;
    
    int amountPaid = readInt("How much did you pay?");
    cout << amountPaid << endl;
    
    repeatChar('*',5);
    
    int m = f(1,2);
    cout << m << endl;
    
    return 0;
}
