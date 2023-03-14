#ifndef HOUSE_H_
#define HOUSE_H_
//Kyle Pish
//02-25-22

#include "hvac.h"

class house{
  public:

    //constructors for the house class
    house(double SquareFeet, double leakage);
    house(double SquareFeet, double leakage, double CoolingDif, double HeatingDif, int CFM);
    //destructor
    ~house();

    //public methods
    int GetSize();
    double GetLeakage();
    double GetTemperature();
    hvac* GetHvac();
    void SimulateDay(double TempArr[], int ArrLength);

  private:
    //private attributes
    double SquareFeet_;
    double leakage_;
    double InternalTemp_;
    hvac* hvacPTR_;

};

#endif