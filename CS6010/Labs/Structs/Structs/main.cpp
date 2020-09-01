//
//  main.cpp
//  Structs
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Politician.hpp"
using namespace std;

void runTests(){
    //Setting up Politicians: Name, Democrat(bool), State(bool)
    Politician mittRomney = {"Mitt Romney", false, false}; //Republican Federal
    Politician pattyMurray = {"Patty Murray", true, false}; // Democrat Federal
    Politician bernieSanders = {"Bernie Sanders", true, false}; // Democrat Federal
    Politician jayInslee = {"Jay Inslee", true, true}; // Democrat State
    Politician garyHerbert = {"Gary Herbert", false, true}; // Republican State
    
    //Creating vectors of politicans
    vector<Politician> politicians = {mittRomney, pattyMurray, bernieSanders, jayInslee, garyHerbert};
    vector<Politician> washington = {pattyMurray, jayInslee};
    vector<Politician> republicans = {mittRomney, garyHerbert};
    
    //Running vectors through the democrat and federal Republican functions
    vector<Politician> democraticPoliticians = democrats(politicians);
    vector<Politician> washingtonDems = democrats(washington);
    vector<Politician> washingtonFedReps = federalRepublicans(washington);
    vector<Politician> whoIsFederalReps = federalRepublicans(republicans);
    vector<Politician> whoIsFederalAll = federalRepublicans(politicians);

    
    // Testing that the functions return the correct size of politicans
    assert(democraticPoliticians.size() == 3);
    assert(washingtonDems.size() == 2);
    assert(washingtonFedReps.size() == 0);
    assert(whoIsFederalReps.size() == 1);
    assert(whoIsFederalAll.size() == 1);
}

int main(int argc, const char * argv[]) {
    runTests();
    return 0;
}
