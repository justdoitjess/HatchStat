// CalculateStats.cpp

#include "CalculateStats.h"
#include <iostream>

CalculateStats::CalculateStats()
   {
   }
   CalculateStats::~CalculateStats()
   {
   }
   void CalculateStats::addNumberToVector(int value)
   {
      this->data.push_back(value);
   }
   double CalculateStats::getMean()
   {
      this->calculateMean();
      return this->mean;
   }
   double CalculateStats::getStdDev()
   {
      this->calculateMean();
      this->calculateStdDev();
      return this->stddev;
   }
   void CalculateStats::calculateMean()
   {
      int dataTotal = this->data.size();
      double sum = 0;
      for (int i = 0; i < dataTotal; i++)
      {
         sum += this->data[i];
      }
      this->mean = sum / dataTotal;
   }
   void CalculateStats::calculateStdDev()
   {
      int dataTotal = this->data.size();
      if (dataTotal < 2)
      {
         this->stddev = -1;
         std::cout << "\n\nNot enough values to calculate "
            << "standard deviation.\n\n";
      }
      else
      {
         double sum = 0;
         double diff = 0;
         double sqr = 0;

         //difference between mean and stddev
         //square it, sum it (cumulative)
         for (int i = 0; i < dataTotal; i++)
         {
            diff = this->mean - this->data[i];
            sqr = diff*diff;
            sum += sqr;
         }
         //average of all those differences squared
         double temp = sum / (dataTotal - 1);
         this->stddev = std::sqrt(temp);
      }//end else()
   }