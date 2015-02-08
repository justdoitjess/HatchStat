class CalculateStats
{
public:
   CalculateStats()
   {
   }
   ~CalculateStats()
   {
   }
   void addNumberToVector(double value)
   {
      this->push_back(value);
   }
   void caluclateStats()
   {
      this->calculateMean();
      this->calculateStdDev();
   }
   double getMean()
   {
      return this->mean;
   }
   double getStdDev()
   {
      return this->stddev;
   }

private:
   void calculateMean()
   {
      int dataTotal = data.size();
      double sum = 0;
      for (int i = 0; i < dataTotal; i++)
      {
         sum = +data[i];
      }
      mean = sum / dataTotal;
   }
   void calculateStdDev()
   {
      
      int dataTotal = data.size();
      double sum = 0;
      double diff = 0;
      double sqr = 0;

      //difference between mean and stddev
      //square it, sum it (cumulative)
      for (int i = 0; i < dataTotal; i++)
      {
         diff = mean - data[i];
         sqr = diff*diff;
         sum = +sqr;
      }
      //average of all those differences squared
      stddev = sum / dataTotal;
   }
   vector<double> data;
   double mean;
   double stddev;
};