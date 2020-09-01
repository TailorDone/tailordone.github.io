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
    Politician mittRomney = {"Mitt Romney", false, false};
    Politician pattyMurray = {"Patty Murray", true, false};
    Politician bernieSanders = {"Bernie Sanders", true, false};
    Politician jayInslee = {"Jay Inslee", true, true};
    Politician garyHerbert = {"Gary Herbert", false, true};
    
    //Creating vectors of politicans
    vector<Politician> politicians = {mittRomney, pattyMurray, bernieSanders, jayInslee, garyHerbert};
    vector<Politician> washington = {pattyMurray, jayInslee};
    
    //Running vectors through the democrat and federal Republican functions
    vector<Politician> democraticPoliticians = democrats(politicians);
    vector<Politician> republicanPoliticians = federalRepublicans(politicians);
    vector<Politician> washingtonDems = democrats(washington);
    vector<Politician> washingtonReps = federalRepublicans(washington);
    
    // Testing that the functions return the correct size of politicans
    assert(democraticPoliticians.size() == 3);
    assert(republicanPoliticians.size() == 2);
    assert(washingtonDems.size() == 2);
    assert(washingtonReps.size() == 0);
    
}

int main(int argc, const char * argv[]) {
    runTests();
    return 0;
}
