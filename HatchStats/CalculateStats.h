//CalculateStats.h

#include <vector>

class CalculateStats
{
public:
   CalculateStats();
   ~CalculateStats();
   void addNumberToVector(int value);
   //void calculateStats();
   double getMean();
   double getStdDev();

private:
   void calculateMean();
   void calculateStdDev();
   std::vector<int> data;
   double mean;
   double stddev;
};