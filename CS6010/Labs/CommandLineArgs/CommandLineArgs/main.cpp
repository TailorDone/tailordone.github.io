//
//  main.cpp
//  CommandLineArgs
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    for(int i = 0; i < argc; i++){
    cout << argv[i] << endl;
    }
    //argv[0] The name of the command being run
    //argc is how many commands there are total (including the name of the command)

    //    Commands in the terminal
    //    taylordunn@Taylors-MacBook-Pro CommandLineArgs % clang++ -std=c++11 -c main.cpp
    //    taylordunn@Taylors-MacBook-Pro CommandLineArgs % clang++ -o main main.o
    //    taylordunn@Taylors-MacBook-Pro CommandLineArgs % ./main one two three
    //    ./main
    //    one
    //    two
    //    three
    return 0;
}
