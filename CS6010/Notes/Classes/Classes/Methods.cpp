//
//  Methods.cpp
//  Classes
//
//  Created by Taylor Dunn on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Methods.hpp"

int c::getx(){
     //(*this).x == this->x
    return x;
}

void c::setx(int x_){
    //this->x = x; Java style
    x=x_; //c__ is don't reuse the same name
}

c::c(int xInit){ //main job is to fill in the member variables
    x = xInit;
    y = x*x;
}

c::c(int xInit, int yInit){
    x=xInit;
    y=yInit;
}


MovingAverage::MovingAverage(int num, double sum_){
    numDataPoints = num;
    sum = sum_;
}

MovingAverage::MovingAverage(){
    numDataPoints = 0;
    sum = 0;
}

MovingAverage::MovingAverage(const std::vector<double>& v){
    numDataPoints = v.size();
    sum = 0;
    for(double x : v){
      sum+=x;
    }
}

//use this -> x
//this == c*
