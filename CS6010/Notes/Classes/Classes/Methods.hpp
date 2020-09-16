//
//  Methods.hpp
//  Classes
//
//  Created by Taylor Dunn on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef Methods_hpp
#define Methods_hpp

#include <stdio.h>
#include <vector>

struct vec{
private: //No one can access these variables from "outside" the struct
    int *data;
    int size, capacity;
};

struct s{
    public : //implicit
};

class c{
private: //implicit
    int x,y;
public:
    int getx(); //method declaration
    void setx(int x_);
public:
    c(int xInit);//Constructor Declaration. No return type. name == name of class or struct
    c(int xiniT, int yInit);
};

class MovingAverage{
    int numDataPoints;
    double sum;
    public:
    int getNumDataPoints(); //Data is somewhere I just need to grab
    double currentAverage(); //Probably involves a computation, so no get
    void addDataPoints(double x);
    MovingAverage(int num, double sum);
    MovingAverage(const std::vector<double>& data);
    MovingAverage();
};


#endif /* Methods_hpp */
