//********************************************************************
// CalulateStats
// main.cpp
// Author: Jessica Hatch
// Date: February 7, 2015
// Class: 605.404 O-O Programming in C++
// Purpose: This program reads in a series of numbers from
// the user and calculates the mean and standard deviation
// These two stats are printed to the screen.
// Input: (from standard input) N doubles
// Output: (to console) The mean and std. deviation of the #s
//********************************************************************
#include "CalculateStats.h"

#include <ctype.h> //For toupper()
#include <iostream>
#include<vector>
using namespace std;

int main(void)
{
   //define lengths and response condition
   char response;
   //get input
   CalculateStats data;
   double input;
   string temp;

   cout << "\n\nThis program will calculate the mean and standard "
      << " deviation of the given list of numbers.\n"
      << "Enter the first number: ";

   //loop over how ever many numbers the user wants to input
   do
   {
      //remove any unread characters that were truncated
      cin.sync();

      //only accept numeric values
      while (!(cin >> input))
      {
         cout << "Bad value!" << "Try again.\n";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      //remove any unread characters that were truncated
      cin.sync();

      //add number to CalculateStats vector
      data.addNumberToVector(input);

      cout << endl;
      cout << "Do you wish to enter another number? "
         << "(Y or N): ";
      cin >> response;
   } while (toupper(response) == 'Y'); //end do while loop

   //calculate the statistics and print results
   data.caluclateStats();
   cout << "The average is: " << data.getMean() << "\n\n";
   cout << "The std dev is: " << data.getStdDev() << "\n\n";

   
   cout << "\nEnd Program.";
   return 0;
} // end main()