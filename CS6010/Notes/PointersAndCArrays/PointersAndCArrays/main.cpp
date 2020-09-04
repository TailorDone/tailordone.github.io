//
//  main.cpp
//  PointersAndCArrays
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
using namespace std;

void f(int arr[3]){
    arr[0] = 100;
    arr[1] = 101;
    arr[2] = 102;
}

// This did not give back an array. Don't do this.
//int[3] g(){
//    int arr[3] = {0,1,2};
//    return arr;
//}

//To understand what is happening, we need to know pointers
//Pointer is an index into the giant list of bytes we call RAM
// int* p //is a pointer to an int. Pointer is an arrow. there is an int at the end of the arrow
//char* s//pointer
//this says s is a pointer to char
//what is actually stored is the address
//dereferencing means "follow the arrow"
//cout << *pi this means follow the arrow
//declaring is an arrow to something
//if i have an arrow or pointer, the star in front means follow the arrow
//we can use this to read or write
// *pi = 10;
//*pi = *pi + 1 (need the starts to follow the arrow every time)
//pi = pi + 1 makes the arrow point somewhere else
//c style swap

void swap (int *a, int *b){
//void swap (int a, int b){
    //int temp = a; mismatched type with an int and an int pointer
    int temp = *a; //follows the arrow to the integer at the end of a
    *a = *b;
    //a = b;
    //b = temp;
    *b = temp; //we want to change the value that b is pointing to to temp
}

void PrintArray(int *arr, int size){
    for (int i = 0; i <size; i ++){
        cout << *(arr + i); //go i int slots past the arr
        //same as arr[i]
        //square brackets means starting with the pointer at the front, go forward i slots
    }
}
//argc (arg count) is the lenght of the array. char * is string char ** is a pointer to string, array of string. argv (arg vector)
int main(int argc, const char * argv[]) {
//    //An array is a data type
//    int myArr[3]; //myArray is a list of 3 ints
//    myArr[0] = 10;
//    cout << myArr[2] << endl;
//    //Size must be known at compile time
//    //No .size() method to tell you the size
      int myArray[3] = {0,1,2};
      PrintArray(myArray, 3);
//    f(myArr); //This changes the array
//
//    int x;
//    int *pi;
//    //if i want to make *pi point to my int
//    pi = &x; //& means "addres of" or "pointer to"
//
    //this is broken and won't work, it's making a copy
    int x = 1;
    int y = 2;
    //swap (t,d); //we cant do this because these are integers and the parameters are
    swap(&x, &y); //pointer to t, pointer to d
    
    return 0;
}
