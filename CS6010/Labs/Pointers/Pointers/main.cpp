//
//  main.cpp
//  Pointers
//
//  Created by Taylor Dunn on 9/15/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

//int* f(){
//    int x = 5;
//    return &x;
//}

//Write a function that takes an array of doubles as a parameter (well, as 2 parameters, a pointer to a double, and the size of the array) and returns a copy of the array (it should return a pointer to the start of the copied array). Test your copy function.
double* copyArray(double* arr, int size){
    double *newArr = new double[size];
    for(int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    return newArr;
}


int main(int argc, const char * argv[]) {
//    int* y = f();
//    std::cout << y << std::endl;
    //The issue is we are returning the address of where x=5 is located on the stack, but once we leave the f() method that information will be removed from the stack, and so the int x=5 will no longer be stored there.
    double arr[10];
    for (int i = 0; i <10; i++){
        arr[i] = i;
    }
    double *newArr = copyArray(arr,10);
    std::cout << arr << " " << newArr << std::endl; //Different memory locations! Yay!
    
    return 0;
}
