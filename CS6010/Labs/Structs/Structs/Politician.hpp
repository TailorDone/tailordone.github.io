//
//  Politician.hpp
//  Structs
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef Politician_hpp
#define Politician_hpp

#include <stdio.h>
#include <string>
using namespace std;

struct Politician{
    string name;
    bool democrat;
    bool state;
};

/*
 * A function that gives a vector of democratic politicians
 * Parameters: politicians A vector of Politicans
 * Returns a vector of democratic politicans
 */
vector<Politician> democrats(vector<Politician> politicians);

/*
 * A function that gives a vector of republican politicans
 * Parameters: politicians A vector of Politicans
 * Returns a vector of republican politicans
 */
vector<Politician> federalRepublicans(vector<Politician> politicians);

#endif /* Politician_hpp */
