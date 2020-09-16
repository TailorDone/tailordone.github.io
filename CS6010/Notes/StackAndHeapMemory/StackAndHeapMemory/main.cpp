//
//  main.cpp
//  StackAndHeapMemory
//
//  Created by Taylor Dunn on 9/15/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    //Stack Memory
    //When calling a function, this allocates memory for all local variables
    //Returning from a function deallocates all the stack memory
    //automatic memory management. #1 choice if possible
    //Issues with the stack.
    //1) Limited size --- Huge data cant go in the stack
    //2) size is not known until runtime. stack fram size must be known at compile time. -- data size not known until runtime, it can't live on the stack.
    //3) stack memory is deallocated when the function returns -- if data needs to outlive the function call, it can't go in the stack
    // Other part of memory is called "the heap"
    // Explicity allocate and deallocate our heap memory
    //If it has a name,usually on the stack, otherwise the heap
    //allocate memory "new"
    //free memory "delete"
    int *pInt = new int; //returns a pointer to memory on the heap big enough to store an int
    pInt = new int[10]; //changed the pointer to the beginning of an array with 10 ints. The first int stays but nothing is pointing to it.
    double *dArr = new double[5]; //Returns a pointer to teh beginning of an array with 5 doubles
    delete pInt; //Says I am finished with what's on the other end of the pointer. it doesn't change the data, doesn't change pointer
    //makes space on heap to hold this data, returns a pointer to beginning of that memomry
    //memory leak is a new with no matching delete. wasted space
    //dangling pointer, pointer to memomry that I shouldn't access
    //use after free (dereference a pointer after deleting)
    //uninitialized pointer use
    int *ip;
    *ip = 10; //probably crash
    
    int *x = new int;
    *x = 1;
    delete x;
    int *y = new int;
    *y = 2;
    *x = 3; //use after free, we said we are done using x, but now we are dereferecning. at this point maye y == 3
    return 0;
    
    int size;
    std::cin >> size;
    //want an array with user definited size
    //Don't know how big it will be until runtime
    int *arr = new int[size]; //better name is pointer to start of array
    for(int i = 0; i < size; i ++){
        //*(arr+i) = i;
        arr[i] = i;
    }
    //What if we wanted to add another entry
    //Have to copy the old values over and then add the 4th
    //Make a new pointer, allocate new array, fill in new array,  deallocate first array
    int *newArr = new int[size+1];
    for (int i = 0; i < size; i ++){
        newArr[i] = arr[i];
    }
    arr[size] = 4;
    delete [] arr;
    arr = newArr; //Changes the pointer to the new array
    newArr = nullptr;
    //use array some more
    delete [] arr;
    arr = nullptr;
    
    int *a = new int;
    *a = 1;
    delete a;
    int*b = new int;
    *b = 2;
    std::cout << *b << std::endl;
    *a = 3;
    std::cout << *a << " " << *b << std::endl;
    std::cout << a << " " << b << std:: endl;
    
    //turn on address sanitizer. edit scheme diagnostics
}
