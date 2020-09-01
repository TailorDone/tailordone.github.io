//
//  Politician.cpp
//  Structs
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Politician.hpp"
#include <vector>

/*
* A function that gives a vector of democratic politicians
* Parameters: politicians A vector of Politicans
* Returns a vector of democratic politicans
*/
vector<Politician> democrats(vector<Politician> politicians){
    vector<Politician> democrats;
    for (Politician person : politicians){
        if (person.democrat == true){
        democrats.push_back(person);
        }
    }
    return democrats;
}

/*
* A function that gives a vector of republican politicans
* Parameters: politicans A vector of Politicans
* Returns a vector of republican politicans
*/
vector<Politician> federalRepublicans(vector<Politician> politicians){
    vector<Politician> fedReps;
    for (Politician person : politicians){
        if (person.democrat == false && person.state == false){
        fedReps.push_back(person);
        }
    }
    return fedReps;
}
