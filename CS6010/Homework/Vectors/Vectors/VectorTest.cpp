/*
  Author: Daniel Kopta and Taylor Dunn
  July 2017
  
  CS 6010 Fall 2019
  Vector util library tests
  Compile this file together with your VectorUtil library with the following command:
  clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp
  Most of the provided tests will fail until you have provided correct
  implementations for the VectorUtil library functions.
  You will need to provide more thorough tests.
*/

#include <iostream>
#include <string>

// Include the VectorUtil library
#include "VectorUtil.h"

/*
 * Helper function for failing a test.
 * Prints a message and exits the program.
 */
void ErrorExit(std::string message)
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1);
}


int main()
{
  
  // Set up some input vectors for testing purposes.

  // We can use list initialization syntax:
  vector<int> v1 = {3, 1, 0, -1, 5};

  // Or we can repeatedly push_back items
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);

  // When testing, be sure to check boundary conditions, such as an empty vector
  vector<int> empty;
    
    vector<int> v4 = {-13, -10, -2, 3, 4, 4, 5};
    vector<int> v5 = {1, 2, 1, 3, 1, 4};
    vector<int> v6 = {3, 3, 3, 3, 3};
    
    //A vector that doesn't start in non-descending, but after pop_back is in descending order. pop also removes the minimum, causing a new minimum
    vector<int> v7;
    v7.push_back(3);
    v7.push_back(4);
    v7.push_back(2);
    v7.pop_back();
    v7.push_back(5);
    
    //A vector with only one element
    vector<int> v8 = {-365};
  
  
  /*
   * Contains tests
   */

  // v1 doesn't contain 4, so this should return false
  if(Contains(v1, 4))
    ErrorExit("Contains test 1");

  // v1 does contain -1, so this should return true
  if(!Contains(v1, -1))
    ErrorExit("Contains test 2");

  /*
   * The vector 'empty' doesn't contain anything, so this should return false
   * The specific value we're looking for here (99) is not important in this test.
   * This test is designed to find any general errors caused by the array being empty.
   * That type of error is unlikely to depend on the value we are looking for.
  */
  if(Contains(empty, 99))
    ErrorExit("Contains empty");
  
  /*
  * Minimum tests
  */
    //The FindMin function will throw an error if the user tries to input an empty vector.
    // v7's minimum is 3 since we pop the 2, so this should return true
    if (FindMin(v7)!= 3)
        ErrorExit("FindMin test 1");
    
    //v8's minimum is , so this should return true
    if (FindMin(v8)!=-365)
        ErrorExit("FindMin test 2");
    
    //v6's minimum is 3, so this should return true
    if(FindMin(v6)!=3)
        ErrorExit("FindMin test 3");
    
    /*
    * Maximum tests
    */
    //The FindMax function will throw an error if the user tries to input an empty vector.
    //v2's maximum is 5, so this should return true
    if(FindMax(v1) != 5)
        ErrorExit("FindMax test 1");
    
    //v2's maximum is 3, so this should return true
    if(FindMax(v2) !=3)
        ErrorExit("FindMax test 2");
    
    //v6's maximum is 3, so this should return true
       if(FindMax(v6)!=3)
           ErrorExit("FindMax test 3");
    
    /*
    * Average tests
    */
    //v2's average is 1.6, which would round to 1, so this should return true
    if(Average(v1) != 1)
        ErrorExit("Average test 1");
    
    //v2's average is 2, so this should return true
    if(Average(v2) !=2)
        ErrorExit("Average test 2");
    
    //v6's average is 3, so this should return true
    if(Average(v6)!=3)
        ErrorExit("Average test 3");
    
    /*
     * IsSorted tets
     */
    //v5 isn't sorted, so this should return false
    if(IsSorted(v5)==true)
        ErrorExit("Sorted test 1");
    
    //v6 is sorted, so this should return true
    if(IsSorted(v6)!=true)
        ErrorExit("Sorted test 2");
    
    //v7 is sorted, so this should return true
    if(IsSorted(v7)!=true)
        ErrorExit("Sorted test 3");
    
  // Since any failed test exits the program, if we made it this far, we passed all tests.
  std::cout << "All tests passed!" << std::endl;
}
